#! /bin/bash

NDKDIR=${HOME}/android-ndk-r5b
#  CC=agcc CXX=agcc CXXFLAGS="-I${NDKDIR}/sources/cxx-stl/stlport/stlport/ -fno-rtti -fno-exceptions" LDFLAGS="-L${NDKDIR}/sources/cxx-stl/stlport/libs/armeabi -lstlport_static" ./nrn-hg/configure --enable-static --disable-shared --without-x --without-nmodl --without-memacs --prefix=`pwd` --host=x86-linux --build=arm-eabi

CC=agcc CXX=agcc CXXFLAGS="-I${NDKDIR}/sources/cxx-stl/gnu-libstdc++/include -I${NDKDIR}/sources/cxx-stl/gnu-libstdc++/libs/armeabi/include -fno-rtti -fno-exceptions" LDFLAGS="-L${NDKDIR}/sources/cxx-stl/gnu-libstdc++/libs/armeabi -lstdc++" ./nrn-hg/configure --enable-static --disable-shared --without-x --without-nmodl --without-memacs --prefix=`pwd` --host=x86-linux --build=arm-eabi
