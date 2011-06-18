/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package org.neurodroid;

import java.io.IOException;

import android.app.Activity;

import android.content.SharedPreferences;

import android.os.Bundle;

import android.view.View;
import android.view.View.OnClickListener;

import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceManager;
import android.preference.CheckBoxPreference;
import android.preference.Preference.OnPreferenceClickListener;

import android.widget.Toast;

public class Preferences extends PreferenceActivity {

    private CheckBoxPreference chkEnableVfp;
    private boolean supportsVfp;
    
    @Override
        protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.preferences);

        supportsVfp = false;
        try {
            supportsVfp = NeuroDroid.cpuSupportsVfp();
        } catch (IOException e) {
            Toast.makeText(this, "Couldn't read cpu info", Toast.LENGTH_SHORT).show();
            supportsVfp = false;
        }

        /* Get previous vfp state */
        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
        boolean prevVfp = prefs.getBoolean("checkbox_vfp", true);
        
        /* Initialise vfp status */
        chkEnableVfp = (CheckBoxPreference)getPreferenceScreen().findPreference("checkbox_vfp");
        if (supportsVfp) {
            chkEnableVfp.setEnabled(true);
            chkEnableVfp.setChecked(prevVfp);
        } else {
            chkEnableVfp.setEnabled(false);
            chkEnableVfp.setChecked(false);
            chkEnableVfp.setSummary("Your cpu doesn't support vfp extensions");
        }
        chkEnableVfp.setOnPreferenceClickListener(new OnPreferenceClickListener() {
                public boolean onPreferenceClick(Preference preference) {
                    if (!supportsVfp) {
                        chkEnableVfp.setChecked(false);
                        Toast.makeText(Preferences.this, "Your cpu doesn't support vfp instructions", Toast.LENGTH_LONG).show();
                        return false;
                    } else {
                        if (chkEnableVfp.isChecked()) {
                            /* NeuroDroid.cpNrnBin(true); */
                            Toast.makeText(Preferences.this, "vfp support enabled", Toast.LENGTH_SHORT).show();
                            return true;
                        } else {
                            /* NeuroDroid.cpNrnBin(false); */
                            Toast.makeText(Preferences.this, "vfp support disabled", Toast.LENGTH_SHORT).show();
                            return false;
                        }
                    }
                }});
        
    }
}
