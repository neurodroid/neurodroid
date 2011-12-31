/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

import android.app.Activity;

import android.content.Intent;

import android.os.Bundle;

public class Graph extends Activity {

    public GraphView gv;

    /** Called when the activity is first created. */
    @Override public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.graph);
        
        gv = (GraphView)findViewById(R.id.vwGraphView);

        double[] array = getIntent().getDoubleArrayExtra("csh.neurodroid.grapharray");
    }

}
