/*
 * Copyright (C) 2011 Steven Luo
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package csh.neurodroid;

import android.app.ListActivity;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;

import csh.neurodroid.model.UpdateCallback;
import csh.neurodroid.session.TermSession;
import csh.neurodroid.util.SessionList;

public class WindowList extends ListActivity {
    private SessionList sessions;
    private WindowListAdapter mWindowListAdapter;
    private TermService mTermService;

    class WindowListAdapter extends BaseAdapter implements UpdateCallback {
        private LayoutInflater inflater = getLayoutInflater();

        public int getCount() {
            return sessions.size();
        }

        public Object getItem(int position) {
            return sessions.get(position);
        }

        public long getItemId(int position) {
            return position;
        }

        public View getView(int position, View convertView, ViewGroup parent) {
            View child = inflater.inflate(R.layout.window_list_item, parent, false);
            TextView label = (TextView) child.findViewById(R.id.window_list_label);
            label.setText(getString(R.string.window_title, position + 1));

            View close = child.findViewById(R.id.window_list_close);
            final TermService service = mTermService;
            final int closePosition = position;
            close.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                    TermSession session = service.getSessions().remove(closePosition);
                    if (session != null) {
                        session.finish();
                        notifyDataSetChanged();
                    }
                }
            });

            return child;
        }

        public void onUpdate() {
            notifyDataSetChanged();
        }
    }

    private ServiceConnection mTSConnection = new ServiceConnection() {
        public void onServiceConnected(ComponentName className, IBinder service) {
            TermService.TSBinder binder = (TermService.TSBinder) service;
            mTermService = binder.getService();
            populateList();
        }

        public void onServiceDisconnected(ComponentName arg0) {
            mTermService = null;
        }
    };

    @Override
    public void onCreate(Bundle icicle) {
        super.onCreate(icicle);

        setTitle(R.string.window_list);

        ListView listView = getListView();
        View newWindow = getLayoutInflater().inflate(R.layout.window_list_new_window, listView, false);
        listView.addHeaderView(newWindow, null, true);

        setResult(RESULT_CANCELED);
    }

    @Override
    protected void onResume() {
        super.onResume();

        Intent TSIntent = new Intent(this, TermService.class);
        if (!bindService(TSIntent, mTSConnection, BIND_AUTO_CREATE)) {
            Log.w(TermDebug.LOG_TAG, "bind to service failed!");
        }
    }

    @Override
    protected void onPause() {
        super.onPause();

        if (sessions != null) {
            sessions.removeCallback(mWindowListAdapter);
        }
        unbindService(mTSConnection);
    }

    private void populateList() {
        sessions = mTermService.getSessions();

        if (mWindowListAdapter == null) {
            WindowListAdapter adapter = new WindowListAdapter();
            setListAdapter(adapter);
            mWindowListAdapter = adapter;
        } else {
            mWindowListAdapter.notifyDataSetChanged();
        }
        sessions.addCallback(mWindowListAdapter);
    }

    @Override
    protected void onListItemClick(ListView l, View v, int position, long id) {
        Intent data = new Intent();
        data.putExtra(Term.EXTRA_WINDOW_ID, position-1);
        setResult(RESULT_OK, data);
        finish();
    }
}
