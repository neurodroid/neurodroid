#! /bin/bash

CC=agcc CXX=agcc ./nrn-hg/configure --enable-static --disable-shared --without-x --with-nmodl-only --prefix=`pwd` --host=x86-linux --build=arm-eabi
