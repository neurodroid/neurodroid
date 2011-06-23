/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

import java.io.*;

import java.util.Enumeration;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

import android.app.Activity;
import android.app.ProgressDialog;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.Instrumentation;

import android.widget.TextView;
import android.widget.Button;
import android.widget.Toast;
import android.widget.CheckBox;

import android.os.Bundle;
import android.os.Environment;

import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MenuInflater;
import android.view.View.OnClickListener;
import android.view.Gravity;
import android.view.LayoutInflater;

import android.util.Log;

import android.content.Intent;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.content.Context;
import android.content.ComponentName;
import android.content.ActivityNotFoundException;
import android.content.res.Resources;

import android.preference.PreferenceManager;

import android.net.Uri;

public class NeuroDroid extends Activity
{

    public String fHoc;
    public static final String TAG = "neurodroid";
    public static final String CACHEDIR = "/data/data/csh.neurodroid/cache";
    public static final String BINDIR = "/data/data/csh.neurodroid";
    public static final String NRNBIN = BINDIR + "/nrniv";
    public static final String NRNHOME = BINDIR + "/nrnhome";
    
    private boolean supportsVfp;
    private CheckBox chkEnableVfp;
    
    private String nrnoutput="", nrnversion, curHocFile;
    private static final String[] HOC_ASSETS = {"benchmark.hoc", "squid.hoc"};
    private static final int REQUEST_SAVE=0, REQUEST_LOAD=1, REQUEST_PREFS=2,
        REQUEST_SQUID_BACK=3;
    private static final int DIALOG_ANDROIDTERM=0, DIALOG_MARKETNOTFOUND=1;
    private ProgressDialog pd;
    private TextView tv;

    private Resources resources;
    
    /** Called when the activity is first created. */
    @Override public void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        resources = getResources();
        
        /* Create directories */
        File cacheDir = new File(CACHEDIR);
        if (!cacheDir.exists()) {
            cacheDir.mkdirs();
        }
        
        tv = (TextView)findViewById(R.id.txtOutput);
        
        /* Check whether the cpu supports vfp instructions */
        supportsVfp = false;
        try {
            supportsVfp = cpuSupportsVfp();
        } catch (IOException e) {
            Toast.makeText(this, "Couldn't read cpu info", Toast.LENGTH_SHORT).show();
            supportsVfp = false;
        }

        /* Get previous vfp state */
        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
        boolean prevVfp = prefs.getBoolean("checkbox_vfp", true);
        
        /* Copy the nrniv binary to binDir and make executable.
         * Use vfp only if it's both supported and enabled in the preferences.
         */
        cpNrnBin(supportsVfp && prevVfp);
        
        /* Get version information from NEURON */
        String[] cmdlist = {NRNBIN, "-c", "print nrnversion()"};
        nrnversion = runBinary(cmdlist, NRNHOME);
        Log.v(TAG, "Neuron version: " + nrnversion);

        /* Load hoc file using a simple file dialog */
        Button buttonLoadFile = (Button)findViewById(R.id.btnLoadFile);
        buttonLoadFile.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    Intent intent = new Intent(getBaseContext(),
                                               FileDialog.class);
                    intent.putExtra(FileDialog.START_PATH, "/sdcard");
                    startActivityForResult(intent, REQUEST_LOAD);
                }});

        /* Test std library */
        Button buttonTestStd = (Button)findViewById(R.id.btnTestStd);
        buttonTestStd.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    String stdcmd = "if (load_file(\"stdrun.hoc\")==1)" +
                        "print \"Successfully opened standard library\"" +
                        "else print \"Failed to open standard library\"";
                    String[] cmdlist = {NRNBIN, "-c", stdcmd};
                    nrnoutput = runBinary(cmdlist, NRNHOME);
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

        /* Run neuron in terminal */
        Button buttonTerm = (Button)findViewById(R.id.btnTerm);
        buttonTerm.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    Intent intent = new Intent(Intent.ACTION_MAIN);
                    intent.setComponent(new ComponentName("jackpal.androidterm", "jackpal.androidterm.Term"));
                    String initCmd = "cd /data/data/csh.neurodroid/ && NEURONHOME=" + NRNHOME + " ./nrniv";
                    intent.putExtra("jackpal.androidterm.iInitialCommand", initCmd);
                    try {
                        startActivity(intent);
                    } catch (ActivityNotFoundException e) {
                        showDialog(DIALOG_ANDROIDTERM);
                        tv.setText(nrnversion + "\n" +
                                   "Couldn't find Android Terminal Emulator. You can get it from the Market.");
                    }
                }});

        /* Check whether we need to install the std lib */
        if (!(new File(NRNHOME + "/lib/hoc/stdlib.hoc")).exists()) {
            pd =  ProgressDialog.show(this,
                                       "Please wait...", "Installing standard library...", true);
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
            String bmfile = CACHEDIR + "/" + HOC_ASSETS[i];
            if (!(new File(bmfile)).exists()) {
                saveAssetsFile(HOC_ASSETS[i], bmfile);
            }
        }
    }
    
    @Override protected Dialog onCreateDialog(int id) {
        switch (id) {
         case DIALOG_ANDROIDTERM:
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
                 .setNegativeButton(R.string.cancel, new DialogInterface.OnClickListener() {
                         public void onClick(DialogInterface dialog, int whichButton) {

                             /* Return silently */
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
         default:
             return super.onOptionsItemSelected(item);
        }
    }

    
    public void runBenchmark(View v) {
        runHoc("Running benchmark...", "benchmark.hoc");
    }
    
    public void runSquid(View v) {
        Intent squidActivity = new Intent(getBaseContext(),
                                          Squid.class);
        squidActivity.putExtra("csh.neurodroid.NrnHome", NRNHOME);
        startActivity(squidActivity);
    }

    public void runHoc(String msg, String hocfile) {
        tv.setText(nrnversion + "\n" + msg);
        tv.invalidate();
        pd = ProgressDialog.show(this,
                                  "Please wait...", msg, true);
        fHoc = hocfile;
        new Thread(new Runnable(){
                public void run(){
                    String bmfile = CACHEDIR + "/" + fHoc;
                    String[] cmdlist = {NRNBIN, bmfile};
                    nrnoutput = runBinary(cmdlist, NRNHOME, false);
                    runOnUiThread(new Runnable(){
                            @Override public void run() {
                                if (pd.isShowing())
                                    pd.dismiss();
                                tv.setText(nrnversion + "\n" + nrnoutput);
                            }
                        });
                }
            }).start();
            
    }
    
    public static boolean cpuSupportsVfp() throws IOException {
        /* Read cpu info */
        FileInputStream fis = new FileInputStream("/proc/cpuinfo");
        Scanner scanner = new Scanner(fis);
        String NL = System.getProperty("line.separator");

        boolean vfp = false;
        try {
            Log.v(TAG, "Parsing /proc/cpuinfo for vfp support");
            while (scanner.hasNextLine()) {
                if (!vfp && (scanner.findInLine("vfpv3")!=null)) {
                    vfp = true;
                }
                Log.v(TAG, scanner.nextLine());
            }
        }
        finally {
            scanner.close();
        }
        
        return vfp;
    }

    public String cpuInfo() {
        StringBuffer strContent = new StringBuffer("");
        try {
            FileInputStream fis = new FileInputStream("/proc/cpuinfo");
            int ch;
            while( (ch = fis.read()) != -1)
                strContent.append((char)ch);
        } catch (IOException e) {
            Log.e(TAG, "Couldn't read /proc/cpuinfo");
            return "";
        }
        return strContent.toString();
    }
    
    /* Copy an assets file to the cache directory */
    public void saveAssetsFile(String src, String target) {

        String newfn;
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

    public static String runBinary(String[] binName, String nrnHome) {
        return runBinary(binName, nrnHome, false);
    }

    /* Run a binary using binDir as the wd. Return stdout
     * and optinally stderr
     */
    public static String runBinary(String[] binName, String nrnHome, boolean stderr) {
        try {
            File binDir = new File(BINDIR);
            if (!binDir.exists()) {
                binDir.mkdirs();
            }
            
            /* Can't set the environment on Android <= 2.2 with
             * ProcessBuilder. Resorting back to old-school Process.exec.
             */
            String[] envp = {"NEURONHOME="+nrnHome};
            Process process = Runtime.getRuntime().exec(binName, envp, binDir);
            process.waitFor();
            
            Scanner outscanner = new Scanner(process.getInputStream());
            Scanner errscanner = new Scanner(process.getErrorStream());
            String NL = System.getProperty("line.separator");
            
            String output = "";
            
            try {
                while (outscanner.hasNextLine()) {
                    output += outscanner.nextLine();
                    output += NL;
                }
            }
            finally {
                outscanner.close();
            }
            if (stderr) {
                output += NL + "stderr:" + NL;
                try {
                    while (errscanner.hasNextLine()) {
                        output += errscanner.nextLine() + NL;
                    }
                }
                finally {
                    errscanner.close();
                }
            }

            return output;

        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    public static ArrayList<Float> parseNrnOut(String nrnOut) {
        Scanner outscanner = new Scanner(nrnOut);
        ArrayList<Float> flArray = new ArrayList<Float>();
        flArray.add(1.0f); /* dt */
        try {
            while (outscanner.hasNextLine()) {
                if (outscanner.findInLine("ND") != null) {
                    if (outscanner.findInLine("dt") != null) {
                        if (outscanner.hasNextFloat()) {
                            flArray.set(0, outscanner.nextFloat());
                        }
                    }
                    if (outscanner.hasNextFloat()) {
                        flArray.add(outscanner.nextFloat());
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
    
    /* Install NEURON std lib that is included as a zip
     * file in the assets
     */
    public void installStdLib() {
        String newfn = CACHEDIR + "/lib.zip";
        saveAssetsFile("lib.zip", newfn);

        UnZip u = new UnZip();
        u.setMode(UnZip.EXTRACT);

        u.unZip(newfn, NRNHOME);

        /* Make readable */
        String[] chmodlist1 = {getChmod(), "755", BINDIR};
        runBinary(chmodlist1, NRNHOME);

        String[] chmodlist2 = {getChmod(), "755", NRNHOME};
        runBinary(chmodlist2, NRNHOME);

        String[] chmodlist3 = {getChmod(), "755", NRNHOME + "/lib"};
        runBinary(chmodlist3, NRNHOME);

        String[] chmodlist4 = {getChmod(), "755", NRNHOME + "/lib/hoc"};
        runBinary(chmodlist4, NRNHOME);

        /* Make cleanup executable */
        String cleanup = NRNHOME + "/lib/cleanup";
        String[] chmodlist6 = {getChmod(), "755", cleanup};
        runBinary(chmodlist6, NRNHOME);
    }

    public static String getChmod() {
        String chmod = "/system/bin/chmod";
        if (!(new File(chmod)).exists()) {
            chmod = "/system/xbin/chmod";
            if (!(new File(chmod)).exists()) {
                throw new RuntimeException("Couldn't find chmod on your system");
            }
        }
        return chmod;
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
                     
                 curHocFile = data.getStringExtra(FileDialog.RESULT_PATH);
                 Log.v(TAG, curHocFile);
                     
                 String[] nrncmd = {NRNBIN, curHocFile};
                 nrnoutput = runBinary(nrncmd, NRNHOME);
                     
                 tv.setText(nrnversion + "\n" + nrnoutput);
                     
             } else if (resultCode == Activity.RESULT_CANCELED) {
                 Log.v(TAG, "file not selected");
             }
             break;
         case REQUEST_PREFS:
             SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
             boolean useVfp = prefs.getBoolean("checkbox_vfp", true);
             cpNrnBin(useVfp);
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

    /* Copy nrniv to binDir and make executable */
    public void cpNrnBin(boolean withVfp) {
        String arch = "armeabi";
        if (withVfp) {
            arch += "-v7a";
        }
            
        File binDir = new File(BINDIR);
        if (!binDir.exists()) {
            throw new RuntimeException("Couldn't find binary directory");
        }

        /* Catenate split files */
        Log.v(TAG, "Looking for assets in " + arch);
        try {
            String[] assetsFiles = getAssets().list(arch);

            File newf = new File(NRNBIN);
            FileOutputStream os = new FileOutputStream(newf);
            for (int i=0; i<assetsFiles.length; i++) {
                Log.v(TAG, "Found NEURON binary part: " + assetsFiles[i]);
                InputStream is = getAssets().open(arch + "/" + assetsFiles[i]);

                byte[] buffer = new byte[is.available()]; 

                is.read(buffer);

                os.write(buffer);

                is.close();
            }
            os.close();
        }
        catch (IOException e) {
            throw new RuntimeException(e);
        }

        String[] chmodlist = {getChmod(), "755", NRNBIN};
        String chmodout = runBinary(chmodlist, NRNHOME);
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
