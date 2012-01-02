#! /bin/bash

NCURSES="5.9"

./config-x86-nmodl.sh
make clean
make -j8
mkdir -p ./armeabi/x86/bin/
mkdir -p ./armeabi-v7a/x86/bin/
cp -v ./src/nmodl/nocmodl ./armeabi/x86/bin/nocmodl
cp -v ./src/nmodl/nocmodl ./armeabi-v7a/x86/bin/nocmodl

cp -v config-arm-ncurses.sh ncurses-${NCURSES}
cd ncurses-${NCURSES}
./config-arm-ncurses.sh
make clean
make -j12
cp -v lib/libncurses.a ../
cd ..

./config-arm-nrn.sh
make -j12
make install

cd ncurses-${NCURSES}
./config-arm-ncurses.sh 1
make clean
make -j12
cp lib/libncurses.a ../
cd ..

./config-arm-nrn.sh 1
make -j12
make install

./cplibs-static.py
