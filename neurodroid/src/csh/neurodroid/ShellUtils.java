// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

// Copyright (c) 2012, Christoph Schmidt-Hieber

package csh.neurodroid;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import android.util.Log;

public class ShellUtils {

    private static String getChmod() throws IOException {
        String chmod = "/system/bin/chmod";
        if (!(new File(chmod)).exists()) {
            chmod = "/system/xbin/chmod";
            if (!(new File(chmod)).exists()) {
                throw new IOException("Couldn't find chmod on your system");
            }
        }
        return chmod;
    }
    
    public static void chmod(String filePath, String mod)
            throws IOException, InterruptedException
    {
        String[] chmodlist = {getChmod(), mod, filePath};
        ShellUtils.runBinary(chmodlist);
    }
    
    public static boolean supportsFuse() {
        return (new File("/dev/fuse")).exists();
    }
    
    public static String runBinary(String[] binName)
            throws IOException, InterruptedException
    {
        return runBinary(binName, "/", false, false, null, null);
    }

/*    public static String runBinary(String[] binName, String binDir, boolean stderr)
            throws IOException, InterruptedException
    {
        return runBinary(binName, binDir, stderr, false, null, null);
    }
*/
    /** Run a binary using binDir as the wd. Return stdout
     *  and optinally stderr
     * @throws IOException 
     * @throws InterruptedException 
     */
    public static String runBinary(String[] binName, String binDirPath, boolean stderr, boolean root,
            String toStdIn, String[] envPrepend)
            throws IOException, InterruptedException
    {
        File binDir = new File(binDirPath);
        if (!binDir.exists()) {
            binDir.mkdirs();
        }
 
        /* Can't set the environment on Android <= 2.2 with
         * ProcessBuilder. Resorting back to old-school exec.
         */
        ArrayList<String> envp = new ArrayList<String>();
        if (envPrepend != null && envPrepend.length > 1 && envPrepend.length % 2 ==0) {
            for (int nenv=0; nenv<envPrepend.length; nenv+=2) {
                envp.add(envPrepend[nenv] + "=" + envPrepend[nenv+1]);
            }
        }
        Process process = Runtime.getRuntime().exec(binName, 
                envp.toArray(new String[0]), binDir);
        process.waitFor();
        
        Scanner outscanner = new Scanner(process.getInputStream());
        Scanner errscanner = new Scanner(process.getErrorStream());
        String NL = System.getProperty("line.separator");
        
        String output = "";
        
        try {
            while (outscanner.hasNextLine()) {
                output += outscanner.nextLine();
                output += NL;
            }
        }
        finally {
            outscanner.close();
        }
        if (stderr) {
            output += NL + "stderr:" + NL;
            try {
                while (errscanner.hasNextLine()) {
                    output += errscanner.nextLine() + NL;
                }
            }
            finally {
                errscanner.close();
            }
        }

        return output;        
    }
    
    public static boolean isMounted(String mountName) {
        boolean isMounted = false;
        try {
            /* Read mounted info */
            FileInputStream fis = new FileInputStream("/proc/mounts");
            Scanner scanner = new Scanner(fis);
            try {
                while (scanner.hasNextLine() && !isMounted) {
                    if (!isMounted && scanner.findInLine(mountName)!=null) {
                        isMounted = true;
                    }
                    scanner.nextLine();
                }
            } finally {
                scanner.close();
            }
        } catch (IOException e) {
            return isMounted;
        }
        return isMounted;
    }
    
    public static boolean cpuSupportsVfp() throws IOException {
        /* Read cpu info */
        FileInputStream fis = new FileInputStream("/proc/cpuinfo");
        Scanner scanner = new Scanner(fis);
        System.getProperty("line.separator");

        boolean vfp = false;
        try {
            Log.v(NeuroDroid.TAG, "Parsing /proc/cpuinfo for vfp support");
            while (scanner.hasNextLine()) {
                if (!vfp && (scanner.findInLine("vfpv3")!=null)) {
                    vfp = true;
                }
                Log.v(NeuroDroid.TAG, scanner.nextLine());
            }
        }
        finally {
            scanner.close();
        }
        
        return vfp;
    }

    public static String cpuInfo() {
        StringBuffer strContent = new StringBuffer("");
        try {
            FileInputStream fis = new FileInputStream("/proc/cpuinfo");
            int ch;
            while( (ch = fis.read()) != -1)
                strContent.append((char)ch);
        } catch (IOException e) {
            Log.e(NeuroDroid.TAG, "Couldn't read /proc/cpuinfo");
            return "";
        }
        return strContent.toString();
    }

}
