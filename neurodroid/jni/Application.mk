BUILDJNI         := false
APP_PROJECT_PATH := $(call my-dir)/../
ifeq (($BUILDJNI), true)
APP_MODULES      := neurodroid-jni
APP_STL          := gnustl_static
endif
