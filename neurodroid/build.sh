#! /bin/bash
# ndk-build
# cp -v jni/prebuilt/libncurses.so libs/armeabi/
ant clean
ant debug
adb uninstall csh.neurodroid
adb install bin/neurodroid-debug.apk
