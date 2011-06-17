#! /bin/bash

if test -n "$1"; then
    ARCH=armeabi-v7a
else
    ARCH=armeabi
fi

TARGET=`pwd`/${ARCH}

./nrn-hg/configure --without-x --with-nmodl-only --prefix=${TARGET}
