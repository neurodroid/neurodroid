#! /bin/bash

NDKDIR=${HOME}/android-ndk-r6b

if test -n "$1"; then
    MYAGCC=agcc-vfp
    ARCH=armeabi-v7a
else
    MYAGCC=agcc
    ARCH=armeabi
fi

TARGET=`pwd`/${ARCH}

CC=${MYAGCC} CXX=${MYAGCC} LDFLAGS="-L`pwd`/.." ./configure --prefix=${TARGET} --host=x86-linux --build=arm-eabi --without-cxx-binding
