# neurodroid
NEURON on Android

This is a port of the [NEURON simulation environment]([http://www.neuron.yale.edu) to arm/Android. It consists of:
  * Patches to the NEURON source code and scripts to cross-compile NEURON for arm/Android on a Linux host.
  * An Android application including the prebuilt binaries to control NEURON from a graphical user interface.
![](http://dl.dropbox.com/u/1972518/nrn-android/screenshot.jpg)
![](http://dl.dropbox.com/u/1972518/nrn-android/screenshot2.jpg)

## Installation
neurodroid is available from the Android Market:
http://market.android.com/details?id=csh.neurodroid

Or from [here](http://code.google.com/p/neurodroid/downloads/list).

## Build
See BuildInstructions.

## Benchmark
*CPU*                                       | *Clock speed* | *Time*
--------------------------------------------|---------------|-------
NVidia Tegra 2, vfp extensions enabled, -O3 | 1.0 GHz       | 5.10s
NVidia Tegra 2, vfp extensions enabled, -O3 | 1.2 GHz       | 4.21s
NVidia Tegra 2, no vfp support, -O2         | 1.0 GHz       | 6.18s
TI OMAP 4430, vfp extensions enabled, -O3   | 1.0 GHz       | 5.11s
TI OMAP 4430, no vfp support, -O2           | 1.0 GHz       | 6.14s
Intel Xeon E5530                            | 2.4 GHz       | 0.52s
