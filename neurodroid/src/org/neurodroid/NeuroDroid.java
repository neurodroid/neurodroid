/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package org.neurodroid;

import java.io.*;

import java.util.Enumeration;
import java.util.Scanner;
import java.util.Map;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

import android.app.Activity;
import android.app.ProgressDialog;
import android.app.AlertDialog;

import android.widget.TextView;
import android.widget.Button;
import android.widget.Toast;
import android.widget.CheckBox;

import android.os.Bundle;

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

import android.preference.PreferenceManager;

public class NeuroDroid extends Activity
{

    public String fHoc;
    public static final String TAG = "neurodroid";
    public static final String CACHEDIR = "/data/data/org.neurodroid/cache";
    public static final String BINDIR = "/data/data/org.neurodroid";
    public static final String NRNBIN = BINDIR + "/nrniv";
    public static final String NRNHOME = BINDIR + "/nrnhome";
    
    private boolean supportsVfp;
    private CheckBox chkEnableVfp;
    
    private String nrnoutput="", nrnversion, curHocFile;
    private static final String[] HOC_ASSETS = {"benchmark.hoc", "squid.hoc"};
    private static final int REQUEST_SAVE=0, REQUEST_LOAD=1, REQUEST_PREFS=2,
        REQUEST_SQUID_BACK=3;
    private ProgressDialog pd;
    private TextView tv;
    
    /** Called when the activity is first created. */
    @Override public void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

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
        nrnversion = runBinary(cmdlist);
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
                    nrnoutput = runBinary(cmdlist);
                    tv.setText(nrnversion + "\n" + nrnoutput);
                }});

        /* Test std library */
        Button buttonTerm = (Button)findViewById(R.id.btnTerm);
        buttonTerm.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    Intent intent = new Intent(Intent.ACTION_MAIN);
                    intent.setComponent(new ComponentName("jackpal.androidterm", "jackpal.androidterm.Term"));
                    try {
                        startActivity(intent);
                    } catch (ActivityNotFoundException e) {
                        tv.setText(nrnversion + "\n" +
                                   "Couldn't find Android Terminal Emulator. You can get it from the Market.");
                    }
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
        squidActivity.putExtra("org.neurodroid.NeuroDroid.NRNBIN", NRNBIN);
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
                    nrnoutput = runBinary(cmdlist, false);
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
            Log.e(TAG, "Couldn't find assets file; exiting now");
            throw new RuntimeException(e);
        }
        
    }

    public static String runBinary(String[] binName) {
        return runBinary(binName, false);
    }

    /* Run a binary using binDir as the wd. Return stdout
     * and optinally stderr
     */
    public static String runBinary(String[] binName, boolean stderr) {
        try {
            File binDir = new File(BINDIR);
            if (!binDir.exists()) {
                binDir.mkdirs();
            }

            List binNameList = Arrays.asList(binName);
            ProcessBuilder pb = new ProcessBuilder(binNameList).directory(binDir);
            Map<String, String> env = pb.environment();
            env.put("NEURONHOME", NRNHOME);

            Process process = pb.start();
            // Waits for the command to finish.
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

        /* Make cleanup executable */
        String cleanup = NRNHOME + "/lib/cleanup";
        String[] chmodlist = {getChmod(), "744", cleanup};
        String chmodout = runBinary(chmodlist);
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
                 nrnoutput = runBinary(nrncmd);
                     
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
        File binDir = new File(BINDIR);
        if (!binDir.exists()) {
            throw new RuntimeException("Couldn't find binary directory");
        }
        if (withVfp) {
            saveAssetsFile("armeabi-v7a/nrniv", NRNBIN);
        } else {
            saveAssetsFile("armeabi/nrniv", NRNBIN);
        }

        String[] chmodlist = {getChmod(), "744", NRNBIN};
        String chmodout = runBinary(chmodlist);
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
