package csh.neurodroid;

import android.test.ActivityInstrumentationTestCase;

import csh.neurodroid.NeuroDroid;

/**
 * This is a simple framework for a test of an Application.  See
 * {@link android.test.ApplicationTestCase ApplicationTestCase} for more information on
 * how to write and extend Application tests.
 * <p/>
 * To run this test, you can type:
 * adb shell am instrument -w \
 * -e class csh.neurodroid.NeuroDroidTest \
 * csh.neurodroid.tests/android.test.InstrumentationTestRunner
 */
public class NeuroDroidTest extends ActivityInstrumentationTestCase<NeuroDroid> {

    public NeuroDroidTest() {
        super("csh.neurodroid.NeuroDroid", NeuroDroid.class);
    }

    /**
     * Verifies that the activity under test can be launched.
     */
    public void testActivityTestCaseSetUpProperly() {
        assertNotNull("activity should be launched successfully", getActivity());
    }

}
