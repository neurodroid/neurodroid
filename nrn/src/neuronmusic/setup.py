#setup.py for neuronmusic extension
from distutils.core import setup, Extension

nrn_srcdir = "./nrn-hg"
instdir = "/home/cs/neurodroid/nrn/armeabi-v7a"
if nrn_srcdir[0] != '/' :
    nrn_srcdir = '../../' + nrn_srcdir

mpicc_bin = "agcc-vfp"
mpicxx_bin = "agcc-vfp"
import os
os.environ["CC"]=mpicc_bin
os.environ["CXX"]=mpicxx_bin

include_dirs = ['.', nrn_srcdir+'/src/neuronmusic', '.']
libdirs = ['.']

neuronmusic_module = Extension(
    'neuronmusic',
    ['neuronmusic.cpp'],
    library_dirs = libdirs,
    libraries = ['music'],
    include_dirs = include_dirs
)

setup(name="neuronmusic", version="7.2",
    description = "NEURON+MUSIC python interface",
    package_dir = {'':instdir+'/share/nrn/lib/python'},
    ext_modules=[neuronmusic_module]
)
