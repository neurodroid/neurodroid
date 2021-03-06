#! /usr/bin/python

import glob
import shutil
import sys
import subprocess
import os

def cpfile(src, target):
    sys.stdout.write("Copying %s to %s\n" % (src, target))
    shutil.copy(src, target)

archs = ["armeabi", "armeabi-v7a"]

for arch in archs:
    try:
        os.makedirs("../neurodroid/assets/%s" % arch)
    except os.error:
        pass

    # Split into 1M chunks for Android <= 2.2:
    p = subprocess.Popen("/usr/bin/split -b 1m nrniv nrniv.split", 
                         cwd="./%s/x86/bin" % arch, 
                         shell=True)
    p.wait()

    splitfiles = glob.glob("./%s/x86/bin/nrniv.split*" % arch)
    print splitfiles
    for splitfile in splitfiles:
        cpfile(splitfile, "../neurodroid/assets/%s/" % arch)

cpfile("benchmark.hoc", "../neurodroid/assets/benchmark.hoc")
cpfile("squid.hoc", "../neurodroid/assets/squid.hoc")
cpfile("squid_std.txt", "../neurodroid/assets/squid_std.txt")

# Seemingly there's nothing architecture-dependent in the library so that we only need to do this once:
p = subprocess.Popen("/usr/bin/zip -r lib.zip *", cwd="./armeabi/share/nrn", shell=True)
p.wait()
cpfile("./armeabi/share/nrn/lib.zip",  "../neurodroid/assets/lib.zip")
