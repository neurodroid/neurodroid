#! /bin/bash
# ndk-build
# cp -v jni/prebuilt/libncurses.so libs/armeabi/
rm -rf bin/*
ant debug
adb uninstall csh.neurodroid
adb install bin/neurodroid-debug.apk
