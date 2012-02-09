#! /bin/bash

NDKDIR=${HOME}/android-ndk-r7
MYAR=arm-linux-androideabi-ar
MYRANLIB=arm-linux-androideabi-ranlib
MYNM=arm-linux-androideabi-nm
MYSTRIP=arm-linux-androideabi-strip

if test -n "$1"; then
    MYAGCC=agcc-vfp
    ARCH=armeabi-v7a
else
    MYAGCC=agcc
    ARCH=armeabi
fi

TARGET=`pwd`/${ARCH}

LIBSTDCXXINC="-I${NDKDIR}/sources/cxx-stl/gnu-libstdc++/include -I${NDKDIR}/sources/cxx-stl/gnu-libstdc++/libs/armeabi/include"
LIBSTDCXXLIB="-L${NDKDIR}/sources/cxx-stl/gnu-libstdc++/libs/armeabi -lgnustl_static"

AR=${MYAR} RANLIB=${MYRANLIB} NM=${MYNM} STRIP=${MYSTRIP} CC=${MYAGCC} CXX=${MYAGCC} \
    CXXFLAGS="${LIBSTDCXXINC} -fexceptions -frtti" \
    LDFLAGS="${LIBSTDCXXLIB} -L`pwd`" \
    ./nrn-hg/configure --enable-static --disable-shared --without-x --without-nmodl --with-gnu-ld --prefix=${TARGET} --host=x86-linux --build=arm-eabi
