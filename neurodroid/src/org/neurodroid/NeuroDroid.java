/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package org.neurodroid;

import java.io.*;
import java.util.Enumeration;

import android.app.Activity;
import android.app.ProgressDialog;
import android.widget.TextView;
import android.widget.Button;
import android.widget.Toast;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.util.Log;
import android.content.Intent;

public class NeuroDroid extends Activity
{

    private String nrnoutput, nrnversion, curHocFile;
    private static final String cacheDirN = "/data/data/org.neurodroid/cache";
    private static final String binDirN = "/data/data/org.neurodroid";
    private static final String nrnbin = binDirN + "/nrniv";
    private static final String nrnhome = binDirN + "/nrnhome";
    private static final String TAG = "NeuroDroid";
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
        File cacheDir = new File(cacheDirN);
        if (!cacheDir.exists()) {
            cacheDir.mkdirs();
        }

        File binDir = new File(binDirN);
        if (!binDir.exists()) {
            binDir.mkdirs();
        }

        /* Copy nrniv to binDir and make executable */
        SaveAssetsFile("nrniv", nrnbin);

        /* Check for chmod */
        String chmod = "/system/bin/chmod";
        if (!(new File(chmod)).exists()) {
            chmod = "/system/xbin/chmod";
            if (!(new File(chmod)).exists()) {
                throw new RuntimeException("Couldn't find chmod on your system");
            }
        }
        String[] chmodlist = {chmod, "744", nrnbin};
        String chmodout = RunBinary(chmodlist);

        tv = (TextView)findViewById(R.id.txtOutput);

        /* Get version information from NEURON */
        String[] cmdlist = {nrnbin, "-c", "print nrnversion()"};
        nrnversion = RunBinary(cmdlist);
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
                    String[] cmdlist = {nrnbin, "-c", stdcmd};
                    nrnoutput = RunBinary(cmdlist);
                    tv.setText(nrnversion + "\n" + nrnoutput);
                }});

        /* Check whether we need to install the std lib */
        if (!(new File(nrnhome + "/lib/hoc/stdlib.hoc")).exists()) {
            pd =  ProgressDialog.show(this,
                                      "Please wait...", "Installing standard library...", true);
            new Thread(new Runnable(){
                    public void run(){
                        installStdLib();
                        pd.dismiss();
                    }
                }).start();
        }
        tv.setText(nrnversion);
    }

    /* Copy an assets file to the cache directory */
    public void SaveAssetsFile(String src, String target) {

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

    public String RunBinary(String[] binName) {
        return RunBinary(binName, false);
    }

    /* Run a binary using binDir as the wd. Return stdout
     * and optinally stderr
     */
    public String RunBinary(String[] binName, boolean stderr) {
        try {
            // Executes the command.
            String[] envp = {"NEURONHOME=" + nrnhome};
            File binDir = new File(binDirN);
            if (!binDir.exists()) {
                binDir.mkdirs();
            }
            Process process = Runtime.getRuntime().exec(binName, envp, binDir);

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
        String newfn = cacheDirN + "/lib.zip";
        SaveAssetsFile("lib.zip", newfn);

        UnZip u = new UnZip();
        u.setMode(UnZip.EXTRACT);

        u.unZip(newfn, binDirN + "/nrnhome");
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

            String[] nrncmd = {nrnbin, curHocFile};
            nrnoutput = RunBinary(nrncmd);

            tv.setText(nrnversion + "\n" + nrnoutput);

        } else if (resultCode == Activity.RESULT_CANCELED) {
            Log.v(TAG, "file not selected");
        }

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
