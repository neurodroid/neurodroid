/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package org.neurodroid;

import android.app.Activity;

import android.widget.Button;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;

public class Squid extends Activity {

    /** Called when the activity is first created. */
    @Override public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setResult(RESULT_OK, getIntent());

        setContentView(R.layout.squid);

        Button backButton = (Button)findViewById(R.id.btnSquidBack);
        backButton.setOnClickListener(new OnClickListener() {
                @Override public void onClick(View v) {
                    finish();
                }
            });
    }
}
