#!/bin/sh

prefix=/home/cs/neurodroid/nrn/armeabi
exec_prefix=/home/cs/neurodroid/nrn/armeabi/x86
NRNBIN=${exec_prefix}/bin
ARCH=x86
NEURONHOME=/home/cs/neurodroid/nrn/armeabi/share/nrn

cd $1

if [ -x ${ARCH}/special ] ; then
	program="./${ARCH}/special"
else
	program="${NRNBIN}/nrniv"
fi

hostname
pwd
shift
shift
echo "time $program $*"
time $program $*

