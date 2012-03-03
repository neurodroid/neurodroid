/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

import java.io.*;

import java.util.Scanner;
import java.util.ArrayList;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.ActivityManager.RunningServiceInfo;
import android.app.ProgressDialog;
import android.app.AlertDialog;
import android.app.Dialog;

import android.widget.TextView;
import android.widget.Button;
import android.widget.Toast;

import android.os.Bundle;
import android.os.Environment;

import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MenuInflater;
import android.view.View.OnClickListener;

import android.util.Log;

import android.content.Intent;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.content.Context;
import android.content.ComponentName;
import android.content.ActivityNotFoundException;
import android.content.pm.PackageManager;
import android.content.pm.PackageInfo;

import android.net.Uri;

import android.text.SpannableString;
import android.text.util.Linkify;
import android.text.method.ScrollingMovementMethod;

import android.graphics.drawable.Drawable;

public class NeuroDroid extends Activity
{

    public static final String TAG = "neurodroid";
    public static final String CACHEPNT = "cache";
    public static final String NRNBINNAME = "nrniv";
    public static final int TERM_UNAVAILABLE=0, TERM_OUTDATED=1, TERM_AVAILABLE=2;
    public String fHoc;
    
    private static final String HOMEPNT = "nrnhome";
    private static final String[] HOC_ASSETS = {"benchmark.hoc", "squid.hoc", "squid_std.txt"};
    private static final int REQUEST_SAVE=0, REQUEST_LOAD=1, REQUEST_PREFS=2,
        REQUEST_SQUID_BACK=3;
    private static final int DIALOG_MARKETNOTFOUND=0, DIALOG_TERM_UNAVAILABLE=1;

    private ProgressDialog pd;
    private TextView tv;
    private boolean supportsVfp, currentPrompt;
    private String nrnoutput="", nrnversion, curHocFile;
    private File binDir, cacheDir, extDir;
    private String nrnBinPath, nrnHomePath;

    /** Called when the activity is first created. */
    @Override public void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        getResources();
        
        /* Create directories */
        cacheDir = getDir(CACHEPNT, Context.MODE_PRIVATE);
        if (!cacheDir.exists()) {
            cacheDir.mkdirs();
        }
        
        tv = (TextView)findViewById(R.id.txtOutput);
        
        /* Check whether the cpu supports vfp instructions */
        supportsVfp = false;
        try {
            supportsVfp = ShellUtils.cpuSupportsVfp();
        } catch (IOException e) {
            Toast.makeText(this, "Couldn't read cpu info", Toast.LENGTH_SHORT).show();
            supportsVfp = false;
        }

        /* Get previous vfp state */
        SharedPreferences prefs = getBaseContext().getSharedPreferences("csh.neurodroid_preferences", 0);
        boolean prevVfp = prefs.getBoolean("cb_vfp", true);

        binDir = getFilesDir().getParentFile();
        nrnBinPath = binDir.getPath() + "/" + NRNBINNAME;
        nrnHomePath = getDir(HOMEPNT, Context.MODE_WORLD_READABLE).getPath();
 
        if (externalStorageIsWritable()) {
            extDir = Environment.getExternalStorageDirectory();
        } else {
            extDir = new File("/");
        }
        
        currentPrompt = false;
        
        /* Copy the nrniv binary to binDir and make executable.
         * Use vfp only if it's both supported and enabled in the preferences.
         */
        cpnrnBinPath(supportsVfp && prevVfp);

        /* Get version information from NEURON */
        String[] cmdlist = {nrnBinPath, "-c", "print nrnversion()"};
        nrnversion = runNrn(cmdlist, false);
        Log.v(TAG, "Neuron version: " + nrnversion);

        /* Run terminal with NEURON environment set up */
        Button buttonTermPrompt = (Button)findViewById(R.id.btnTermPrompt);
        buttonTermPrompt.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    /* Check whether a new version of the Terminal
                     * Emulator has been installed
                     */
                    currentPrompt = true;
                    launchTerm(currentPrompt);
                }});

        /* Run neuron in terminal */
        Button buttonTerm = (Button)findViewById(R.id.btnTerm);
        buttonTerm.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    /* Check whether a new version of the Terminal
                     * Emulator has been installed
                     */
                    currentPrompt = false;
                    launchTerm(currentPrompt);
                }});

        /* Load hoc file using a simple file dialog */
        Button buttonLoadFile = (Button)findViewById(R.id.btnLoadFile);
        buttonLoadFile.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    Intent intent = new Intent(getBaseContext(),
                                               FileDialog.class);
                    intent.putExtra(FileDialog.START_PATH, extDir.getPath());
                    intent.putExtra(FileDialog.BUTTON_LABEL, getString(R.string.select));
                    startActivityForResult(intent, REQUEST_LOAD);
                }});

        /* Test std library */
        Button buttonTestStd = (Button)findViewById(R.id.btnTestStd);
        buttonTestStd.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    String stdcmd = "if (load_file(\"stdrun.hoc\")==1)" +
                        "print \"Successfully opened standard library\"" +
                        "else print \"Failed to open standard library\"";
                    String[] cmdlist = {nrnBinPath, "-c", stdcmd};
                    nrnoutput = runNrn(cmdlist, false);
                    tv.setText(nrnversion + "\n" + nrnoutput);
                }});

        /* Benchmark */
        Button buttonBenchmark = (Button)findViewById(R.id.btnBenchmark);
        buttonBenchmark.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    runBenchmark(v);
                }
            });

        /* Squid AP */
        Button buttonSquid = (Button)findViewById(R.id.btnSquid);
        buttonSquid.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    runSquid(v);
                }
            });

        /* Check whether we need to install the std lib */
        if (!(new File(nrnHomePath + "/lib/hoc/stdlib.hoc")).exists()) {
            pd =  ProgressDialog.show(this,
                                      this.getString(R.string.wait_msg), "Installing standard library...", true);
            new Thread(new Runnable(){
                    public void run(){
                        installStdLib();
                        runOnUiThread(new Runnable(){
                                @Override public void run() {
                                    if (pd.isShowing())
                                        pd.dismiss();
                                }
                            });
                    }
                }).start();
        }
        tv.setText(nrnversion);
        
        /* Check whether we need to install hoc files */
        for (int i=0; i<HOC_ASSETS.length; i++) {
            String bmfile = cacheDir.getPath() + "/" + HOC_ASSETS[i];
            if (!(new File(bmfile)).exists()) {
                saveAssetsFile(HOC_ASSETS[i], bmfile);
            }
        }
    }
    
    @Override protected Dialog onCreateDialog(int id) {
        switch (id) {
         case DIALOG_TERM_UNAVAILABLE:
             return new AlertDialog.Builder(NeuroDroid.this)
                 .setIcon(R.drawable.app_terminal)
                 .setTitle(R.string.app_terminal_missing)
                 .setPositiveButton(R.string.app_terminal_get, new DialogInterface.OnClickListener() {
                         public void onClick(DialogInterface dialog, int whichButton) {
                             Intent intent = new Intent(Intent.ACTION_VIEW,
                                                        Uri.parse("market://details?id=jackpal.androidterm"));
                             try {
                                 startActivity(intent);
                             } catch (ActivityNotFoundException e) {
                                 showDialog(DIALOG_MARKETNOTFOUND);
                             }
                         }
                     })
                 .setNegativeButton(R.string.app_terminal_builtin, new DialogInterface.OnClickListener() {
                         public void onClick(DialogInterface dialog, int whichButton) {
                             runTerm(new Intent(getBaseContext(), Term.class), 
                                     currentPrompt, builtinTermRunning());
                         }
                     })
                 .create();
         case DIALOG_MARKETNOTFOUND:
             return new AlertDialog.Builder(NeuroDroid.this)
                 .setIcon(android.R.drawable.ic_dialog_alert)
                 .setTitle(R.string.market_missing)
                 .setPositiveButton(R.string.ok, new DialogInterface.OnClickListener() {
                         public void onClick(DialogInterface dialog, int whichButton) {
                             /* Return silently */
                         }
                     })
                 .create();
        }
        return null;
    }

    /** Creates an options menu */
    @Override public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.menu, menu);
        return true;
    }

    /** Opens the options menu */
    @Override public boolean onOptionsItemSelected(MenuItem item) {
        // Handle item selection
        switch (item.getItemId()) {
         case R.id.preferences:
             Intent settingsActivity = new Intent(getBaseContext(),
                                                  Preferences.class);
             startActivityForResult(settingsActivity, REQUEST_PREFS);
             return true;
         case R.id.about:
             AlertDialog builder;
             try {
                 builder = AboutDialogBuilder.create(this);
                 builder.show();
                 return true;
             } catch (PackageManager.NameNotFoundException e) {
                 // TODO Auto-generated catch block
                 return false;
             }
         default:
             return super.onOptionsItemSelected(item);
        }
    }

    
    public void runBenchmark(View v) {
        runHoc("Running benchmark...", "benchmark.hoc", false);
    }
    
    public void runSquid(View v) {
        Intent squidActivity = new Intent(getBaseContext(),
                                          Squid.class);
        squidActivity.putExtra("csh.neurodroid.nrnHomePath", nrnHomePath);
        squidActivity.putExtra("csh.neurodroid.nrnBinPath", nrnBinPath);
        squidActivity.putExtra("csh.neurodroid.cachePath", cacheDir.getPath());
        startActivity(squidActivity);
    }

    public void runHoc(String msg, String hocfile) {
        runHoc(msg, hocfile, true);
    }
    
    public void runHoc(String msg, String hocfile, final boolean stderr) {
        tv.setText(nrnversion + "\n" + msg);
        tv.invalidate();
        pd = ProgressDialog.show(this,
                                 this.getString(R.string.wait_msg), msg, true);
        fHoc = hocfile;
        new Thread(new Runnable(){
                public void run(){
                    String bmfile = cacheDir.getPath() + "/" + fHoc;
                    String[] cmdlist = {nrnBinPath, bmfile};
                    nrnoutput = runNrn(cmdlist, stderr);
                    runOnUiThread(new Runnable(){
                            @Override public void run() {
                                if (pd.isShowing())
                                    pd.dismiss();
                                if (nrnoutput != null && !nrnoutput.equals("")) {
                                    tv.setText(nrnoutput);
                                } else {
                                    tv.setText(nrnversion);
                                }
                            }
                        });
                }
            }).start();
            
    }

    private boolean builtinTermRunning() {
        ActivityManager manager = (ActivityManager) getSystemService(ACTIVITY_SERVICE);
        for (RunningServiceInfo service : manager.getRunningServices(Integer.MAX_VALUE)) {
             if ("csh.neurodroid.TermService".equals(service.service.getClassName())) {
                 return true;
             }
        }
        return false;
    }
    
    private boolean extTermRunning() {
        ActivityManager manager = (ActivityManager) getSystemService(ACTIVITY_SERVICE);
        for (RunningServiceInfo service : manager.getRunningServices(Integer.MAX_VALUE)) {
             if ("jackpal.androidterm.TermService".equals(service.service.getClassName())) {
                 return true;
             }
        }
        return false;
    }
 
    private void launchTerm(boolean prompt) {
        /* Is a reminal emulator running? */
        SharedPreferences prefs = getBaseContext().getSharedPreferences("csh.neurodroid_preferences", 0);
        boolean useBuiltin = prefs.getBoolean("cb_builtin", true);
        Intent builtinTerm = new Intent(getBaseContext(), Term.class); 
        if (useBuiltin) {
            runTerm(builtinTerm, prompt, builtinTermRunning());
        } else {
            /* If Terminal Emulator is not installed or outdated,
             * offer to download
             */
            if (!useBuiltin && hasExtterm(getBaseContext())!=TERM_AVAILABLE) {
                showDialog(DIALOG_TERM_UNAVAILABLE);
            } else {
                ComponentName termComp = new ComponentName("jackpal.androidterm", "jackpal.androidterm.Term");
                try {
                    PackageInfo pinfo = getBaseContext().getPackageManager().getPackageInfo(termComp.getPackageName(), 0);
                    String patchVersion = pinfo.versionName;
                    Log.v(TAG, "Terminal Emulator version: " + patchVersion);
                    int patchCode = pinfo.versionCode;

                    if (patchCode < 32) {
                        runTerm(builtinTerm, prompt, builtinTermRunning());
                    } else {
                        Intent intent = new Intent(Intent.ACTION_MAIN);
                        intent.setComponent(termComp);
                        runTerm(intent, prompt, extTermRunning());
                    }

                } catch (PackageManager.NameNotFoundException e) {
                    runTerm(builtinTerm, prompt, builtinTermRunning());
                }
            }
        }
    }

    private void runTerm(Intent intent, boolean prompt, boolean running) {
        /* If the terminal is running, abort */
        if (running) {
            new AlertDialog.Builder(NeuroDroid.this)
                .setIcon(android.R.drawable.ic_dialog_alert)
                .setTitle(R.string.warning)
                .setMessage(R.string.term_service_running)
                .setPositiveButton(R.string.ok, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int whichButton) {
                        ;
                    }
                })
                .create().show();
            return;
        }
        
        String initCmd = "cd " + extDir.getPath() + "; " +
                         "export PATH=" + binDir.getPath() + ":${PATH}; " +
                         "export NEURONHOME=" + nrnHomePath + ";";
        if (!prompt) {
            initCmd = "cd /data/data/csh.neurodroid/ && NEURONHOME=" + 
                    nrnHomePath + " ./nrniv";
        }
        intent.putExtra("jackpal.androidterm.iInitialCommand", initCmd);
        startActivity(intent);
    }

    public static int hasExtterm(Context context) {
        ComponentName termComp = new ComponentName("jackpal.androidterm", "jackpal.androidterm.Term");
        try {
            PackageInfo pinfo = context.getPackageManager().getPackageInfo(termComp.getPackageName(), 0);
            int patchCode = pinfo.versionCode;

            if (patchCode < 32) {
                return TERM_OUTDATED;
            } else {
                return TERM_AVAILABLE;
            }
        } catch (PackageManager.NameNotFoundException e) {
            return TERM_UNAVAILABLE;
        }
    }

    /** Copy an assets file to the cache directory */
    public void saveAssetsFile(String src, String target) {

        try {
            InputStream is = getAssets().open(src);

            byte[] buffer = new byte[is.available()]; 

            is.read(buffer);

            File newf = new File(target);
            FileOutputStream os = new FileOutputStream(newf);

            os.write(buffer);

            os.close();
            is.close();
            
        } catch (IOException e) {
            Log.e(TAG, "Couldn't find assets file " + src + "; exiting now");
            throw new RuntimeException(e);
        }
        
    }

    public static ArrayList<Float> parseNrnOut(String nrnOut) {
        Scanner outscanner = new Scanner(nrnOut);
        int len = nrnOut.split("ND").length;
        ArrayList<Float> flArray = new ArrayList<Float>(len+1);
        
        flArray.add(1.0f); // dt
        
        try {
            while (outscanner.hasNextLine()) {
                if (outscanner.findInLine("ND") != null) {
                    if (outscanner.findInLine("dt") != null) {
                        flArray.set(0, new Float(outscanner.next()));
                        /* nextFloat is safer but prohibitively slow
                         * if (outscanner.hasNextFloat()) {
                            flArray.set(0, outscanner.nextFloat());
                        } */
                    } else {
                        flArray.add(new Float(outscanner.next()));
                        /* if (outscanner.hasNextFloat()) {                        
                            flArray.add(outscanner.nextFloat());
                        }*/
                    }
                }
                outscanner.nextLine();
            }
        }
        finally {
            outscanner.close();
        }
        return flArray;
    }
    
    /** Install NEURON std lib that is included as a zip
     *  file in the assets
     */
    public void installStdLib() {
        String newfn = cacheDir.getPath() + "/lib.zip";
        saveAssetsFile("lib.zip", newfn);

        UnZip u = new UnZip();
        u.setMode(UnZip.EXTRACT);

        u.unZip(newfn, nrnHomePath);

        /* Make readable */
        
        try {
            ShellUtils.chmod(nrnBinPath, "755");
            ShellUtils.chmod(nrnHomePath, "755");
            ShellUtils.chmod(nrnHomePath + "/lib", "755");
            ShellUtils.chmod(nrnHomePath + "/lib/hoc", "755");
            ShellUtils.chmod(nrnHomePath + "/lib/cleanup", "755");
        } catch (IOException e) {
            Log.e(TAG, e.getMessage());
        } catch (InterruptedException e) {
            Log.e(TAG, e.getMessage());
        }
    }

    /* Called upon exit from the file dialog */
    public synchronized void onActivityResult(final int requestCode,
                                              int resultCode, final Intent data) {

        switch (requestCode) {
         case REQUEST_SAVE:
         case REQUEST_LOAD:
             /* file dialog */
             if (resultCode == Activity.RESULT_OK) {
                     
                 if (requestCode == REQUEST_SAVE) {
                     System.out.println("Saving...");
                 } else if (requestCode == REQUEST_LOAD) {
                     System.out.println("Loading...");
                 }
                     
                 curHocFile = data.getStringExtra(FileDialog.RESULT_SELECTED_FILE);
                 Log.v(TAG, curHocFile);
                     
                 String[] nrncmd = {nrnBinPath, curHocFile};
                 nrnoutput = runNrn(nrncmd);
                 if (nrnoutput != null && !nrnoutput.equals("")) {
                     tv.setText(nrnoutput);
                 } else {
                     tv.setText(nrnversion);
                 }
                     
             } else if (resultCode == Activity.RESULT_CANCELED) {
                 Log.v(TAG, "file not selected");
             }
             break;
         case REQUEST_PREFS:
             SharedPreferences prefs = getBaseContext().getSharedPreferences("csh.neurodroid_preferences", 0);
             boolean useVfp = prefs.getBoolean("cb_vfp", true);
             cpnrnBinPath(useVfp && supportsVfp);
             if (useVfp) {
                 Log.v(TAG, "Vfp enabled through options");
             } else {
                 Log.v(TAG, "Vfp disabled through options");
             }
             break;
         case REQUEST_SQUID_BACK:
             break;
         default:
             Log.e(TAG, "Unknown request code");
        }
    }

    /** Copy nrniv to binDir and make executable */
    public void cpnrnBinPath(boolean withVfp) {
        String arch = "armeabi";
        if (withVfp) {
            arch += "-v7a";
        }
        binDir.mkdirs();
        if (!binDir.exists()) {
            
            throw new RuntimeException("Couldn't find binary directory");
        }

        /* Catenate split files */
        Log.v(TAG, "Looking for assets in " + arch);
        try {
            String[] assetsFiles = getAssets().list(arch);

            File newf = new File(nrnBinPath);
            FileOutputStream os = new FileOutputStream(newf);
            for (String assetsFile : assetsFiles) {
                Log.v(TAG, "Found NEURON binary part: " + assetsFile);
                InputStream is = getAssets().open(arch + "/" + assetsFile);

                byte[] buffer = new byte[is.available()]; 

                is.read(buffer);

                os.write(buffer);

                is.close();
            }
            os.close();
        }
        catch (IOException e) {
            new AlertDialog.Builder(NeuroDroid.this)
                .setIcon(android.R.drawable.ic_dialog_alert)
                .setTitle(R.string.error)
                .setMessage(R.string.copy_binary_failure)
                .setPositiveButton(R.string.ok, new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int whichButton) {
                            finish();
                        }
                    })
                .create().show();
        }

        try {
            ShellUtils.chmod(nrnBinPath, "755");
        } catch (IOException e) {
            Log.e(TAG, e.getMessage());
        } catch (InterruptedException e) {
            Log.e(TAG, e.getMessage());
        }
     }

    private static class AboutDialogBuilder {
        public static AlertDialog create(Context context) throws PackageManager.NameNotFoundException {
            PackageInfo pInfo = context.getPackageManager().
                getPackageInfo(context.getPackageName(), PackageManager.GET_META_DATA);
            Drawable pIcon = context.getPackageManager().
                getApplicationIcon(context.getPackageName());
            String aboutTitle = String.format("%s %s", context.getString(R.string.app_name), pInfo.versionName);
            String aboutText = context.getString(R.string.about);

            final TextView message = new TextView(context);
            final SpannableString s = new SpannableString(aboutText);

            message.setPadding(5, 5, 5, 5);
            message.setMovementMethod(new ScrollingMovementMethod());
            message.setText(s);
            Linkify.addLinks(message, Linkify.ALL);

            return new AlertDialog.Builder(context).setTitle(aboutTitle).
                setIcon(pIcon).
                setCancelable(true).
                setPositiveButton(context.getString(android.R.string.ok), null).
                setView(message).create();
        }
    }
    
    private String runNrn(String[] cmdList) {
        return runNrn(cmdList, true);
    }
    
    private String runNrn(String[] cmdList, boolean stderr) {
        String nrnout = "";
        String[] env = {"NEURONHOME", nrnHomePath};
        try {
            nrnout = ShellUtils.runBinary(cmdList, nrnHomePath, stderr, false, null, env);
        } catch (IOException e) {
            Log.e(TAG, e.getMessage());
        } catch (InterruptedException e) {
            Log.e(TAG, e.getMessage());
        }
        return nrnout;
    }


    public static boolean externalStorageIsWritable() {
        /* Check sd card state */
        String state = Environment.getExternalStorageState();

        boolean extStorAvailable = false;
        boolean extStorWriteable = false;

        if (Environment.MEDIA_MOUNTED.equals(state)) {
            // We can read and write the media
            extStorAvailable = extStorWriteable = true;
        } else if (Environment.MEDIA_MOUNTED_READ_ONLY.equals(state)) {
            // We can only read the media
            extStorAvailable = true;
            extStorWriteable = false;
        } else {
            // Something else is wrong. It may be one of many other states, but all we need
            //  to know is we can neither read nor write
            extStorAvailable = extStorWriteable = false;
        }

        return extStorAvailable && extStorWriteable;
    }
    
    /* Load libraries for native part of the app.
     */
    static {
        /*
           System.loadLibrary("stlport_shared");
           System.loadLibrary("ncurses");
           System.loadLibrary("neurodroid-jni");
        */
    }
}
