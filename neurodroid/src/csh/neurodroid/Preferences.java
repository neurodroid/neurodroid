/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

import java.io.IOException;

import android.content.SharedPreferences;

import android.os.Bundle;

import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.CheckBoxPreference;
import android.preference.Preference.OnPreferenceClickListener;

import android.widget.Toast;

public class Preferences extends PreferenceActivity {

    private SharedPreferences prefs;
    
    private CheckBoxPreference chkEnableVfp, chkEnableBuiltin;
    private boolean supportsVfp;
    
    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.preferences);

        supportsVfp = false;
        try {
            supportsVfp = NeuroDroid.cpuSupportsVfp();
        } catch (IOException e) {
            Toast.makeText(this, "Couldn't read cpu info", Toast.LENGTH_SHORT).show();
            supportsVfp = false;
        }

        /* Get previous states */
        prefs = getBaseContext().getSharedPreferences("csh.neurodroid_preferences", 0);
        boolean prevVfp = prefs.getBoolean("cb_vfp", true);
        boolean prevBuiltin = prefs.getBoolean("cb_builtin", false);
            
        /* Initialise vfp status */
        chkEnableVfp = (CheckBoxPreference)getPreferenceScreen().findPreference("cb_vfp");
        if (supportsVfp) {
            chkEnableVfp.setEnabled(true);
            chkEnableVfp.setChecked(prevVfp);
        } else {
            chkEnableVfp.setEnabled(false);
            chkEnableVfp.setChecked(false);
            chkEnableVfp.setSummary(getBaseContext().getString(R.string.cb_vfp_summary_disabled));
        }
        chkEnableVfp.setOnPreferenceClickListener(new OnPreferenceClickListener() {
                public boolean onPreferenceClick(Preference preference) {
                    if (!supportsVfp) {
                        chkEnableVfp.setChecked(false);
                        Toast.makeText(Preferences.this, getBaseContext().getString(R.string.cb_vfp_summary_disabled), Toast.LENGTH_LONG).show();
                        return false;
                    } else {
                        if (chkEnableVfp.isChecked()) {
                            Toast.makeText(Preferences.this, "vfp support enabled", Toast.LENGTH_SHORT).show();
                            return true;
                        } else {
                            Toast.makeText(Preferences.this, "vfp support disabled", Toast.LENGTH_SHORT).show();
                            return false;
                        }
                    }
                }});
        
        chkEnableBuiltin = (CheckBoxPreference)getPreferenceScreen().findPreference("cb_builtin");
        /* Initialise builtin terminal status */
        chkEnableBuiltin.setChecked(prevBuiltin);
        chkEnableBuiltin.setOnPreferenceClickListener(new OnPreferenceClickListener() {
                public boolean onPreferenceClick(Preference preference) {
                    if (chkEnableBuiltin.isChecked()) {
                        Toast.makeText(Preferences.this, "Always using built-in terminal", Toast.LENGTH_SHORT).show();
                        return true;
                    } else {
                        Toast.makeText(Preferences.this, "Using external terminal (if available)", Toast.LENGTH_SHORT).show();
                        return false;
                    }
                }});
    }
}
