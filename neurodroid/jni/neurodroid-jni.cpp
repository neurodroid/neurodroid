/*
 * Copyright (c) 2011, Christoph Schmidt-Hieber
 * Distributed under the modified 3-clause BSD license:
 * See the LICENSE file that accompanies this code.
 */

#include <string.h>
#include <jni.h>
#include <dlfcn.h>
#include <unistd.h>
#include <cstdio>
#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif

    extern void hoc_main1_init(char* pname, char** envp);
    extern void hoc_audit_from_hoc_main1(int argc, char** argv, char **envp);
    extern void hoc_main1(int argc, char** argv, char **envp);

/* See the corresponding Java source
 * file located at:
 *
 *   src/csh/neurodroid/NeuroDroid.java
 */
jstring
Java_csh_neurodroid_NeuroDroidJNI_loadNrn( JNIEnv* env,
                                           jobject thiz,
                                           jstring input )
{

    // convert Java string to UTF-8
    const char* utf8 = env->GetStringUTFChars(input, NULL);
    __android_log_print(ANDROID_LOG_DEBUG, "NeuroDroid", "Hoc input: %s", utf8);
    
    int dargc = 2;
    char** dargv = new char*[dargc];
    char** denvp = environ;

    dargv[0] = (char*)"nrnoc";
    dargv[1] = new char[strlen(utf8)+4];
    
    sprintf(dargv[1], "%s", utf8);
    __android_log_print(ANDROID_LOG_DEBUG, "NeuroDroid", "Hoc input: %s", dargv[1]);

    FILE* f1 = fopen("/sdcard/neurodroid/cache/stdout", "wb");
    if (dup2(fileno(f1), 1) < 0) {
        __android_log_print(ANDROID_LOG_ERROR, "NeuroDroid", "Unable to attach stdout");
    }
    fclose(f1);
    
    hoc_main1(dargc, dargv, denvp);

    // release the Java string and UTF-8
    __android_log_print(ANDROID_LOG_DEBUG, "NeuroDroid", "Releasing buffers...");

    
    delete dargv[1];
    delete[] dargv;

    env->ReleaseStringUTFChars(input, utf8);

    return env->NewStringUTF("Hello from neurodroid!");
}

#ifdef __cplusplus
}
#endif
