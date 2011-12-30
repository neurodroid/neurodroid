package csh.neurodroid;

import java.io.*;
import java.util.*;
import java.util.zip.*;
import java.util.List;

import android.util.Log;

/**
 * UnZip -- print or unzip a JAR or PKZIP file using java.util.zip.
 * Command-line version: extracts files.
 * @author  Ian Darwin, Ian@DarwinSys.com
 * $Id: UnZip.java,v 1.7 2004/03/07 17:40:35 ian Exp $
 * Retrieved from: http://java.codefetch.com/example/2s/io/UnZip.java
 * Christoph Schmidt-Hieber, 2011/06/04
 * Minor modifications for android.
 */
public class UnZip {
    /** Constants for mode listing or mode extracting. */
    public static final int LIST = 0, EXTRACT = 1;
    private static final String TAG = "NeuroDroidZip";

    /** Whether we are extracting or just printing TOC */
    protected int mode = EXTRACT;

    /** The ZipFile that is used to read an archive */
    protected ZipFile zippy;

    /** The buffer for reading/writing the ZipFile data */
    protected byte[] b;


    /** Construct an UnZip object. Just allocate the buffer */
    UnZip() {
        b = new byte[8092];
    }

    /** Set the Mode (list, extract). */
    protected void setMode(int m) {
        if (m == LIST ||
            m == EXTRACT)
            mode = m;
    }

    /** Cache of paths we've mkdir()ed. */
    protected SortedSet<String> dirsMade;

    /** For a given Zip file, process each entry. */
    public void unZip(String fileName, String baseDir) {
        dirsMade = new TreeSet<String>();
        try {
            zippy = new ZipFile(fileName);
            Enumeration all = zippy.entries();
            while (all.hasMoreElements()) {
                getFile((ZipEntry)all.nextElement(), baseDir);
            }
        } catch (IOException err) {
            Log.e(TAG, "IO error: " + err);
            return;
        }
    }

    protected boolean warnedMkDir = false;

    /** Process one file from the zip, given its name.
     * Either print the name, or create the file on disk.
     */
    protected void getFile(ZipEntry e, String baseDir) throws IOException {
        String zipName = baseDir + "/" + e.getName();

        String chmod = NeuroDroid.getChmod();
        List<String> chmodlist = new ArrayList<String>();
        chmodlist.add(chmod);
        chmodlist.add("644");
        chmodlist.add("");
        
        switch (mode) {
         case EXTRACT:
             // if (zipName.startsWith("/")) {
             //     if (!warnedMkDir)
             //         Log.v(TAG, "Ignoring absolute paths");
             //     warnedMkDir = true;
             //     zipName = zipName.substring(1);
             // }
             // if a directory, just return. We mkdir for every file,
             // since some widely-used Zip creators don't put out
             // any directory entries, or put them in the wrong place.
             if (zipName.endsWith("/")) {
                 return;
             }
             // Else must be a file; open the file for output
             // Get the directory part.
             int ix = zipName.lastIndexOf('/');
             if (ix > 0) {
                 String dirName = zipName.substring(0, ix);
                 if (!dirsMade.contains(dirName)) {
                     File d = new File(dirName);
                     // If it already exists as a dir, don't do anything
                     if (!(d.exists() && d.isDirectory())) {
                         // Try to create the directory, warn if it fails
                         Log.v(TAG, "Creating Directory: " + dirName);
                         if (!d.mkdirs()) {
                             Log.e(TAG, "Warning: unable to mkdir " + dirName);
                         }
                         dirsMade.add(dirName);
                     }
                 }
             }
             Log.e(TAG, "Creating " + zipName);
             FileOutputStream os = new FileOutputStream(zipName);
             InputStream  is = zippy.getInputStream(e);
             int n = 0;
             while ((n = is.read(b)) >0)
                 os.write(b, 0, n);
             is.close();
             os.close();

             /* chmod to rwr-r- */
             chmodlist.set(2, zipName);
             ProcessBuilder pb = new ProcessBuilder(chmodlist);
             Process process = pb.start();

             break;
         case LIST:
             // Not extracting, just list
             if (e.isDirectory()) {
                 Log.v(TAG, "Directory " + zipName);
             } else {
                 Log.v(TAG, "File " + zipName);
             }
             break;
         default:
             throw new IllegalStateException("mode value (" + mode + ") bad");
        }
    }
}
