/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;

public class Graph extends Activity {

    public GraphView gv;

    /** Called when the activity is first created. */
    @Override public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.graph);
        
        gv = (GraphView)findViewById(R.id.vwGraphView);

        String title = getIntent().getStringExtra("csh.neurodroid.graphtitle");
        @SuppressWarnings("unchecked")
        ArrayList<Float> array = (ArrayList<Float>)getIntent().getSerializableExtra("csh.neurodroid.grapharray");
        @SuppressWarnings("unchecked")
        ArrayList<Float> stdArray = (ArrayList<Float>)getIntent().getSerializableExtra("csh.neurodroid.stdarray");
        gv.setGraph(array, stdArray, title);
        gv.invalidate();
    }

}
