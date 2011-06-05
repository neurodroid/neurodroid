#! /bin/bash

./config-x86-nmodl.sh
make clean
make -j4

./config-arm-nrn.sh
make -j4
make install

./config-arm-nrn.sh 1
make -j4
make install
