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

#  CC=agcc CXX=agcc CXXFLAGS="-I${NDKDIR}/sources/cxx-stl/stlport/stlport/ -fno-rtti -fno-exceptions" LDFLAGS="-L${NDKDIR}/sources/cxx-stl/stlport/libs/${ARCH} -lstlport_static" ./nrn-hg/configure --enable-static --disable-shared --without-x --without-nmodl --without-memacs --prefix=${TARGET} --host=x86-linux --build=arm-eabi

CC=${MYAGCC} CXX=${MYAGCC} CXXFLAGS="-I${NDKDIR}/sources/cxx-stl/gnu-libstdc++/include -I${NDKDIR}/sources/cxx-stl/gnu-libstdc++/libs/${ARCH}/include -fno-rtti -fno-exceptions" LDFLAGS="-L${NDKDIR}/sources/cxx-stl/gnu-libstdc++/libs/${ARCH} -L`pwd` -lstdc++" ./nrn-hg/configure --enable-static --disable-shared --without-x --without-nmodl --without-memacs --with-gnu-ld --prefix=${TARGET} --host=x86-linux --build=arm-eabi
