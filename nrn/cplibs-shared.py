#! /usr/bin/python

import glob
import shutil
import sys

nrnlibs=glob.glob("./x86/lib/*.so.0.0.0")
for nrnlib in nrnlibs:
    newfn = "../jni/project/jni/prebuilt/%s" % nrnlib[10:-6]
    sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
    shutil.copyfile(nrnlib, newfn)

nrnlib = "./libncurses.so"
newfn = "../jni/project/jni/prebuilt/libncurses.so"
sys.stdout.write("Copying %s to %s\n" % (nrnlib, newfn))
shutil.copyfile(nrnlib, newfn)

# nrnbins=glob.glob("./x86/bin/*")
# for nrnbin in nrnbins:
#     newfn = "../jni/project/assets/%s" % nrnbin[10:]
#     sys.stdout.write("Copying %s to %s\n" % (nrnbin, newfn))
#     shutil.copyfile(nrnbin, newfn)
