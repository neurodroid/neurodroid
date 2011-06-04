#! /usr/bin/python

import glob
import shutil
import sys
import subprocess

# nrnlibs=glob.glob("./x86/lib/*.a")
# for nrnlib in nrnlibs:
#     newfn = "../neurodroid/jni/prebuilt/%s" % nrnlib[10:]
#     sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
#     shutil.copyfile(nrnlib, newfn)

# nrnlibs=glob.glob("./x86/lib/*.o")
# for nrnlib in nrnlibs:
#     newfn = "../neurodroid/jni/prebuilt/%s" % nrnlib[10:]
#     sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
#     shutil.copyfile(nrnlib, newfn)

# nrnlib = "./libncurses.so"
# newfn = "../neurodroid/jni/prebuilt/libncurses.so"
# sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
# shutil.copyfile(nrnlib, newfn)

# nrnlib = "./src/oc/modlreg.o"
# newfn = "../neurodroid/jni/prebuilt/modlreg.o"
# sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
# shutil.copyfile(nrnlib, newfn)

# nrnlib = "./src/oc/ockludge.o"
# newfn = "../neurodroid/jni/prebuilt/ockludge.o"
# sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
# shutil.copyfile(nrnlib, newfn)

nrnlib = "./x86/bin/nrniv"
newfn = "../neurodroid/assets/nrniv"
sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
shutil.copyfile(nrnlib, newfn)

p = subprocess.Popen("/usr/bin/zip -r lib.zip *", cwd="/home/cs/Dropbox/nrn-android/nrn/share/nrn", shell=True)
p.wait()
nrnlib = "./share/nrn/lib.zip"
newfn = "../neurodroid/assets/lib.zip"
sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
shutil.copyfile(nrnlib, newfn)
