/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import android.app.Activity;
import android.app.ProgressDialog;

import android.widget.Button;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;
import android.widget.TextView.BufferType;

import android.os.Bundle;

import android.text.Spannable;
import android.text.style.SuperscriptSpan;
import android.util.Log;

import android.view.View;
import android.view.View.OnClickListener;

import android.content.Intent;


public class Squid extends Activity {

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

        Button runButton = (Button)findViewById(R.id.btnSquidRun);
        runButton.setOnClickListener(new OnClickListener() {
                @Override public void onClick(View v) {
                    runSquid();
                }
            });

        SeekBar gnaSeekBar = (SeekBar)findViewById(R.id.sbarSquidGna);
        gnaSeekBar.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromTouch) {
                formatG(mProgressGnaText, progressToGna(progress));
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
        formatG(mProgressGnaText, mGna);

        SeekBar gkSeekBar = (SeekBar)findViewById(R.id.sbarSquidGk);
        gkSeekBar.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromTouch) {
                formatG(mProgressGkText, progressToGk(progress));
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
        formatG(mProgressGkText, mGk);
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
                    // long time0 = System.currentTimeMillis();
                    final String squidOut = NeuroDroid.runBinary(cmdlist, NRNHOME, false);
                    // Log.v(NeuroDroid.TAG, String.format("Run neuron: %d ms", System.currentTimeMillis()-time0));
                    runOnUiThread(new Runnable(){
                            @Override public void run() {
                                if (pd.isShowing()) {
                                    pd.dismiss();
                                }
                                // long time0 = System.currentTimeMillis();
                                ArrayList<Float> values = NeuroDroid.parseNrnOut(squidOut);
                                // Log.v(NeuroDroid.TAG, String.format("Parse neuron output: %d ms", System.currentTimeMillis()-time0));
                                // time0 = System.currentTimeMillis();
                                showGraph(values);
                                // Log.v(NeuroDroid.TAG, String.format("Show graph: %d ms", System.currentTimeMillis()-time0));
                            }
                        });
                }
            }).start();
            
        return nrnoutput;
    }

    private void showGraph(ArrayList<Float> graphArray) {
        Intent graphActivity = new Intent(getBaseContext(), Graph.class);
        graphActivity.putExtra("csh.neurodroid.graphtitle", getString(R.string.squid_name));
        graphActivity.putExtra("csh.neurodroid.grapharray", graphArray);
        /* Read default AP from file */
        try {
            Scanner outscanner = new Scanner(new File(CACHEDIR + "/squid_std.txt"));
            ArrayList<Float> stdArray = new ArrayList<Float>();
            try {
                while (outscanner.hasNextLine()) {
                    stdArray.add(new Float(outscanner.next()));
                    /* nextFloat is safer but prohibitively slow
                    if (outscanner.hasNextFloat()) {
                        stdArray.add(outscanner.nextFloat());
                    } */
                    outscanner.nextLine();
                }
            } finally {
                outscanner.close();
            }
            graphActivity.putExtra("csh.neurodroid.stdarray", stdArray);
        } catch (IOException e) {
            Log.e(NeuroDroid.TAG, CACHEDIR + "/squid_std.txt");
        }

        startActivity(graphActivity);
    }

    private double progressToGna(int progress) {
    	return progress * 1.80 + 30.0;
    }
    
    private double progressToGk(int progress) {
        return progress * 0.36 + 18.0;
    }
    
    private void formatG(TextView tv, double g) {
        tv.setText(String.format("%.1f ", g) + getString(R.string.squid_gunits), BufferType.SPANNABLE);
        Spannable str = (Spannable)tv.getText();
        str.setSpan(new SuperscriptSpan(), str.length()-1, str.length(), Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
    }
}
