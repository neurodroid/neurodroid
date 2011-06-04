package org.neurodroid;

import android.test.ActivityInstrumentationTestCase;

/**
 * This is a simple framework for a test of an Application.  See
 * {@link android.test.ApplicationTestCase ApplicationTestCase} for more information on
 * how to write and extend Application tests.
 * <p/>
 * To run this test, you can type:
 * adb shell am instrument -w \
 * -e class org.neurodroid.neurodroidTest \
 * org.neurodroid.tests/android.test.InstrumentationTestRunner
 */
public class neurodroidTest extends ActivityInstrumentationTestCase<neurodroid> {

    public neurodroidTest() {
        super("org.neurodroid", neurodroid.class);
    }

}
