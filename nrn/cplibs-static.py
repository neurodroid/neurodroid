#! /usr/bin/python

import glob
import shutil
import sys
import subprocess
import os

def cpfile(src, target):
    sys.stdout.write("Copying %s to %s\n" % (src, target))
    shutil.copyfile(src, target)

archs = ["armeabi", "armeabi-v7a"]

for arch in archs:
    try:
        os.makedirs("../neurodroid/assets/%s" % arch)
    except os.error:
        pass

    cpfile("./%s/x86/bin/nrniv" % arch, "../neurodroid/assets/%s/nrniv" % arch)

cpfile("benchmark.hoc", "../neurodroid/assets/benchmark.hoc")

# Seemingly there's nothing architecture-dependent in the library so that we only need to do this once:
p = subprocess.Popen("/usr/bin/zip -r lib.zip *", cwd="./armeabi/share/nrn", shell=True)
p.wait()
cpfile("./armeabi/share/nrn/lib.zip",  "../neurodroid/assets/lib.zip")
