#! /bin/bash

./config-x86-nmodl.sh
make clean
make -j8
mkdir -p ./armeabi/x86/bin/
mkdir -p ./armeabi-v7a/x86/bin/
cp -v ./src/nmodl/nocmodl ./armeabi/x86/bin/nocmodl
cp -v ./src/nmodl/nocmodl ./armeabi-v7a/x86/bin/nocmodl

./config-arm-nrn.sh
make -j8
make install

./config-arm-nrn.sh 1
make -j8
make install

./cplibs-static.py
