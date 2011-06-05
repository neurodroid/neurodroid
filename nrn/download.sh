#! /bin/bash

hg clone -r520 http://www.neuron.yale.edu/hg/neuron/nrn nrn-hg
cp nrn-android.patch nrn-hg
cd nrn-hg
patch -p1 < nrn-android.patch
cd ..
