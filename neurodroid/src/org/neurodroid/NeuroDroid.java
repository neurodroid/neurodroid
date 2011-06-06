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
import java.util.concurrent.CountDownLatch;

import android.app.Activity;
import android.app.ProgressDialog;
import android.app.AlertDialog;
import android.widget.TextView;
import android.widget.Button;
import android.widget.Toast;
import android.widget.CheckBox;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.util.Log;
import android.content.Intent;
import android.content.DialogInterface;

public class NeuroDroid extends Activity
{

    private boolean supportsVfp;
    private CheckBox chkEnableVfp;
    
    private String nrnoutput="", nrnversion, curHocFile;
    private static final String CACHEDIR = "/data/data/org.neurodroid/cache";
    private static final String BINDIR = "/data/data/org.neurodroid";
    private static final String NRNBIN = BINDIR + "/nrniv";
    private static final String NRNHOME = BINDIR + "/nrnhome";
    private static final String TAG = "neurodroid";
    private static final int REQUEST_SAVE=0, REQUEST_LOAD=1;
    private ProgressDialog pd;
    private TextView tv;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        /* Create directories */
        File cacheDir = new File(CACHEDIR);
        if (!cacheDir.exists()) {
            cacheDir.mkdirs();
        }

        /* Check whether the cpu supports vfp instructions */
        supportsVfp = false;
        try {
            supportsVfp = cpuSupportsVfp();
        } catch (IOException e) {
            Toast.makeText(this, "Couldn't read cpu info", Toast.LENGTH_SHORT).show();
            supportsVfp = false;
        }
        
        tv = (TextView)findViewById(R.id.txtOutput);

        /* Copy the nrniv binary to binDir and make executable */
        cpNrnBin(supportsVfp);
        
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

        /* Benchmark */
        Button buttonBenchmark = (Button)findViewById(R.id.btnBenchmark);
        buttonBenchmark.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    runBenchmark(v);
                }
            });

        /* Enable vfp extension */
        chkEnableVfp = (CheckBox)findViewById(R.id.chkEnableVfp);
        if (supportsVfp) {
            chkEnableVfp.setChecked(true);
        } else {
            chkEnableVfp.setChecked(false);
        }
        chkEnableVfp.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    if (!NeuroDroid.this.supportsVfp) {
                        NeuroDroid.this.chkEnableVfp.setChecked(false);
                        Toast.makeText(NeuroDroid.this, "Your cpu doesn't support vfp instructions", Toast.LENGTH_LONG).show();
                    } else {
                        if (NeuroDroid.this.chkEnableVfp.isChecked()) {
                            cpNrnBin(true);
                            Toast.makeText(NeuroDroid.this, "vfp support enabled", Toast.LENGTH_LONG).show();
                        } else {
                            cpNrnBin(false);
                            Toast.makeText(NeuroDroid.this, "vfp support disabled", Toast.LENGTH_LONG).show();
                        }
                    }
                }});
        
        /* Check whether we need to install the std lib */
        if (!(new File(NRNHOME + "/lib/hoc/stdlib.hoc")).exists()) {
            final ProgressDialog pd2 =  ProgressDialog.show(this,
                                      "Please wait...", "Installing standard library...", true);
            new Thread(new Runnable(){
                    public void run(){
                        installStdLib();
                        runOnUiThread(new Runnable(){
                                @Override
                                    public void run() {
                                    if(pd2.isShowing())
                                        pd2.dismiss();
                                }
                            });
                    }
                }).start();
        }
        tv.setText(nrnversion);
    }
    
    public void runBenchmark(View v) {
        tv.setText(nrnversion + "\n" + "Running benchmark...");
        tv.invalidate();
        final ProgressDialog pd2 = ProgressDialog.show(this,
                                                       "Please wait...", "Running benchmark...", true);
        new Thread(new Runnable(){
                public void run(){
                    String bmfile = CACHEDIR+"/benchmark.hoc";
                    saveAssetsFile("benchmark.hoc", bmfile);
                    String[] cmdlist = {NRNBIN, bmfile};
                    nrnoutput = runBinary(cmdlist);
                    runOnUiThread(new Runnable(){
                            @Override
                                public void run() {
                                if(pd2.isShowing())
                                    pd2.dismiss();
                                tv.setText(nrnversion + "\n" + nrnoutput + cpuInfo());
                            }
                        });
                }
            }).start();
            
    }
    
    public boolean cpuSupportsVfp() throws IOException {
        /* Read cpu info */
        FileInputStream fis = new FileInputStream("/proc/cpuinfo");
        Scanner scanner = new Scanner(fis);
        String NL = System.getProperty("line.separator");

        boolean vfp = false;
        try {
            Log.v(TAG, "Parsing /proc/cpuinfo for vfp support");
            while (scanner.hasNextLine()){
                if (!vfp && (scanner.findInLine("vfpv3")!=null)) {
                    vfp = true;
                }
                Log.v(TAG, scanner.nextLine());
            }
        }
        finally{
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
            // Should never happen!
            throw new RuntimeException(e);
        }
        
    }

    public String runBinary(String[] binName) {
        return runBinary(binName, false);
    }

    /* Run a binary using binDir as the wd. Return stdout
     * and optinally stderr
     */
    public String runBinary(String[] binName, boolean stderr) {
        try {
            File binDir = new File(BINDIR);
            if (!binDir.exists()) {
                binDir.mkdirs();
            }

            List binNameList = Arrays.asList(binName);
            /* Process process = Runtime.getRuntime().exec(binName, envp, binDir);*/
            ProcessBuilder pb = new ProcessBuilder(binNameList).directory(binDir);
            Map<String, String> env = pb.environment();
            env.put("NEURONHOME", NRNHOME);

            Process process = pb.start();
            // Waits for the command to finish.
            process.waitFor();

            BufferedReader outreader = new BufferedReader(
                                                          new InputStreamReader(process.getInputStream()));
            BufferedReader errreader = new BufferedReader(
                                                          new InputStreamReader(process.getErrorStream()));

            int read;
            char[] buffer = new char[32768];
            StringBuffer output = new StringBuffer();
            while ((read = outreader.read(buffer)) > 0) {
                output.append(buffer, 0, read);
            }
            if (stderr) {
                while ((read = errreader.read(buffer)) > 0) {
                    output.append(buffer, 0, read);
                }
            }

            outreader.close();
            errreader.close();

            return output.toString();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
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
    }

    /* Called upon exit from the file dialog */
    public synchronized void onActivityResult(final int requestCode,
                                              int resultCode, final Intent data) {

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

        /* Check for chmod */
        String chmod = "/system/bin/chmod";
        if (!(new File(chmod)).exists()) {
            chmod = "/system/xbin/chmod";
            if (!(new File(chmod)).exists()) {
                throw new RuntimeException("Couldn't find chmod on your system");
            }
        }
        String[] chmodlist = {chmod, "744", NRNBIN};
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
