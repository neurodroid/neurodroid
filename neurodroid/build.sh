#! /bin/bash
# ndk-build
# cp -v jni/prebuilt/libncurses.so libs/armeabi/
ant debug
adb uninstall org.neurodroid
adb install bin/neurodroid-debug.apk
