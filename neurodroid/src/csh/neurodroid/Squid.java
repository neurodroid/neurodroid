/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.concurrent.CountDownLatch;

import android.app.Activity;
import android.app.ProgressDialog;

import android.widget.Button;

import android.os.Bundle;

import android.view.View;
import android.view.View.OnClickListener;

import android.content.Intent;

import android.util.Log;

public class Squid extends Activity {

    public GraphView gv;

    private String NRNBIN, BINDIR, NRNHOME, CACHEDIR;
    private String fHoc;
    private ProgressDialog pd;
    private String nrnoutput;
    
    /** Called when the activity is first created. */
    @Override public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        NRNBIN = NeuroDroid.NRNBIN;
        BINDIR = NeuroDroid.BINDIR;
        CACHEDIR = NeuroDroid.CACHEDIR;

        Intent intent = getIntent();
        NRNHOME = intent.getStringExtra("csh.neurodroid.NrnHome");

        setContentView(R.layout.squid);

        gv = (GraphView)findViewById(R.id.vwGraphView);

        Button runButton = (Button)findViewById(R.id.btnSquidRun);
        runButton.setOnClickListener(new OnClickListener() {
                @Override public void onClick(View v) {
                    runHoc("Running squid AP simulation...", "squid.hoc");
                }
            });

        Button backButton = (Button)findViewById(R.id.btnSquidBack);
        backButton.setOnClickListener(new OnClickListener() {
                @Override public void onClick(View v) {
                    finish();
                }
            });

    }

    public String runHoc(String msg, String hocfile) {
        pd = ProgressDialog.show(this,
                                 "Please wait...", msg, true);
        fHoc = hocfile;
        new Thread(new Runnable(){
                public void run(){
                    String bmfile = CACHEDIR + "/" + fHoc;
                    String[] cmdlist = {NRNBIN, bmfile};
                    final String squidOut = NeuroDroid.runBinary(cmdlist, NRNHOME, false);
                    runOnUiThread(new Runnable(){
                            @Override public void run() {
                                if (pd.isShowing()) {
                                    pd.dismiss();
                                }
                                ArrayList<Float> values = NeuroDroid.parseNrnOut(squidOut);
                                gv.setGraph(values, "Squid Action Potential");
                                gv.invalidate();
                            }
                        });
                }
            }).start();
            
        return nrnoutput;
    }
}
