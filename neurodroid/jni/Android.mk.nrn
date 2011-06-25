LOCAL_PATH := $(call my-dir)
DROID = "/home/cs/android-cm/system"
TOOLCHAIN = "/home/cs/android-ndk-r5b/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86"

ifeq ($(BUILDJNI), true)
include $(CLEAR_VARS)
LOCAL_MODULE := ncurses-prebuilt
LOCAL_SRC_FILES := ./prebuilt/libncurses.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_LDLIBS    := $(LOCAL_PATH)/prebuilt/nvkludge.o $(LOCAL_PATH)/prebuilt/modlreg.o $(LOCAL_PATH)/prebuilt/ockludge.o -loc -lnrnoc -lnrniv -livoc -lscopmath -lsparse13 -lnrnmpi -ldl -llog -lncurses
LOCAL_LDFLAGS   += -L$(LOCAL_PATH)/prebuilt -nostdlib -Wl,-T,$(DROID)/build/core/armelf.xsc -Wl,--gc-sections -Wl,--no-whole-archive -lc -lm $(TOOLCHAIN)/lib/gcc/arm-linux-androideabi/4.4.3/libgcc.a -Wl,--whole-archive
LOCAL_CFLAGS    := -fno-exceptions
LOCAL_CXXFLAGS    := -fno-exceptions
LOCAL_CPPFLAGS    := -fno-exceptions
LOCAL_SHARED_LIBRARY := ncurses-prebuilt 
LOCAL_MODULE    := neurodroid-jni
LOCAL_SRC_FILES := neurodroid-jni.cpp

include $(BUILD_SHARED_LIBRARY)

# agcc -g -O2 -o .libs/nrnoc ocmain.o nrnnoiv.o ocnoiv.o cprop.o ../oc/modlreg.o  -lstlport -lncurses ./.libs/libnrnoc.so ../oc/.libs/liboc.so ../scopmath/.libs/libscopmath.so ../sparse13/.libs/libsparse13.so ../nrnmpi/.libs/libnrnmpi.so -lm -ldl -Wl,-rpath -Wl,/home/cs/Dropbox/nrn-android/nrn/x86/lib

# agcc -I/home/cs/android-ndk-r5b/sources/cxx-stl/stlport/stlport -fno-rtti -fno-exceptions -o nrniv nvkludge.o ../ivoc/nrnmain.o ../ivoc/ivocmain.o ../oc/modlreg.o ../oc/ockludge.o  ../nrnoc/.libs/libnrnoc.a ../oc/.libs/liboc.a ./.libs/libnrniv.a ../ivoc/.libs/libivoc.a ../nrnmpi/.libs/libnrnmpi.a ../gnu/.libs/libneuron_gnu.a ../scopmath/.libs/libscopmath.a ../sparse13/.libs/libsparse13.a ../sundials/.libs/libsundials.a ../mesch/.libs/libmeschach.a ../ivos/.libs/libivos.a -lstlport -lncurses -lm -ldl
endif
