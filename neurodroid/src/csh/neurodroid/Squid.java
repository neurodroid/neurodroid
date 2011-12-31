/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import android.app.Activity;
import android.app.ProgressDialog;

import android.widget.Button;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;

import android.os.Bundle;

import android.util.Log;

import android.view.View;
import android.view.View.OnClickListener;

import android.content.Intent;


public class Squid extends Activity {

    public GraphView gv;

    private String NRNBIN, NRNHOME, CACHEDIR, RAWHOC, RUNHOC;
    private ProgressDialog pd;
    private String nrnoutput;
    private double mGna, mGk;
    
    TextView mProgressGnaText, mProgressGkText;
    
    /** Called when the activity is first created. */
    @Override public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        NRNBIN = NeuroDroid.NRNBIN;
        CACHEDIR = NeuroDroid.CACHEDIR;
        RAWHOC = CACHEDIR + "/squid.hoc";
        RUNHOC = CACHEDIR + "/squid_run.hoc";

        Intent intent = getIntent();
        NRNHOME = intent.getStringExtra("csh.neurodroid.NrnHome");

        setContentView(R.layout.squid);

        gv = (GraphView)findViewById(R.id.vwSquidGraphView);

        Button runButton = (Button)findViewById(R.id.btnSquidRun);
        runButton.setOnClickListener(new OnClickListener() {
                @Override public void onClick(View v) {
                    runSquid();
                }
            });

        Button backButton = (Button)findViewById(R.id.btnSquidBack);
        backButton.setOnClickListener(new OnClickListener() {
                @Override public void onClick(View v) {
                    finish();
                }
            });

        SeekBar gnaSeekBar = (SeekBar)findViewById(R.id.sbarSquidGna);
        gnaSeekBar.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromTouch) {
                mProgressGnaText.setText(formatG(progressToGna(progress)));
                mGna = progressToGna(progress);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                mGna = progressToGna(seekBar.getProgress());
            }
            
        });
        mProgressGnaText = (TextView)findViewById(R.id.tvSquidGnaProgress);
        mGna = progressToGna(gnaSeekBar.getProgress());
        mProgressGnaText.setText(formatG(mGna));

        SeekBar gkSeekBar = (SeekBar)findViewById(R.id.sbarSquidGk);
        gkSeekBar.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromTouch) {
                mProgressGkText.setText(formatG(progressToGk(progress)));
                mGk = progressToGk(progress);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                mGk = progressToGk(seekBar.getProgress());
            }
            
        });
        mProgressGkText = (TextView)findViewById(R.id.tvSquidGkProgress);
        mGk = progressToGk(gkSeekBar.getProgress());
        mProgressGkText.setText(formatG(mGk));
}

    public String runSquid() {
        pd = ProgressDialog.show(this,
                                 this.getString(R.string.wait_msg), 
                                 this.getString(R.string.squid_msg), true);
        new Thread(new Runnable(){
                public void run(){
                    String initString = String.format("gna=%.4f\ngk=%.4f\n", mGna*1e-3, mGk*1e-3);
                    try {
                        BufferedReader in = new BufferedReader(new FileReader(RAWHOC));
                        BufferedWriter out = new BufferedWriter(new FileWriter(RUNHOC));
                        out.write(initString);
                        int c;
                        while ((c = in.read()) != -1)
                          out.write(c);

                        in.close();
                        out.close();
                    } catch (IOException e) {
                        Log.e(NeuroDroid.TAG, CACHEDIR + "/squid*.hoc");
                    }
                    String[] cmdlist = {NRNBIN, RUNHOC};
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
    
    private double progressToGna(int progress) {
    	return progress * 1.80 + 30.0;
    }
    
    private double progressToGk(int progress) {
        return progress * 0.36 + 18.0;
    }
    
    private String formatG(double g) {
        return String.format("%.1f", g) + " mS / cm^2";       
    }
}
