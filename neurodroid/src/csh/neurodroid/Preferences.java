/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

package csh.neurodroid;

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

    private SharedPreferences prefs;
    
    private CheckBoxPreference chkEnableVfp; //, chkEnableExtterm;
    private boolean supportsVfp;
    /* private int supportsExtterm;*/
    
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

        /* supportsExtterm = NeuroDroid.hasExtterm(getBaseContext());*/
        
        /* Get previous states */
        prefs = getBaseContext().getSharedPreferences("csh.neurodroid_preferences", 0);
        boolean prevVfp = prefs.getBoolean("cb_vfp", true);
        /* boolean prevExtterm = prefs.getBoolean("cb_extterm", false);*/
            
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
        
        /* Initialise extterm status
        chkEnableExtterm = (CheckBoxPreference)getPreferenceScreen().findPreference("cb_extterm");
        switch (supportsExtterm) {
         case NeuroDroid.TERM_AVAILABLE:
            chkEnableExtterm.setEnabled(true);
            chkEnableExtterm.setChecked(prevExtterm);
            break;
         case NeuroDroid.TERM_UNAVAILABLE:
            chkEnableExtterm.setEnabled(false);
            chkEnableExtterm.setChecked(false);
            chkEnableExtterm.setSummary(getBaseContext().getString(R.string.cb_extterm_summary_unavailable));
            break;
         case NeuroDroid.TERM_OUTDATED:
            chkEnableExtterm.setEnabled(false);
            chkEnableExtterm.setChecked(false);
            chkEnableExtterm.setSummary(getBaseContext().getString(R.string.cb_extterm_summary_outdated));
            break;
        }

        chkEnableExtterm.setOnPreferenceClickListener(new OnPreferenceClickListener() {
                public boolean onPreferenceClick(Preference preference) {
                    if (supportsExtterm!=NeuroDroid.TERM_AVAILABLE) {
                        chkEnableExtterm.setChecked(false);
                        return false;
                    } else {
                        if (chkEnableExtterm.isChecked()) {
                            Toast.makeText(Preferences.this, "Using external terminal", Toast.LENGTH_SHORT).show();
                            return true;
                        } else {
                            Toast.makeText(Preferences.this, "Using built-in terminal", Toast.LENGTH_SHORT).show();
                            return false;
                        }
                    }
                }});
        */
    }
}
