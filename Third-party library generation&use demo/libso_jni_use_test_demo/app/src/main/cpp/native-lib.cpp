#include <jni.h>
#include <string>
#include "include/test.h"
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_demo3_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_demo3_MainActivity_Jniaddtest(JNIEnv *env, jobject thiz, jint a, jint b) {
    // TODO: implement Jniaddtest()
    int result = Jniadd(a,b);

    return result;
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demo3_MainActivity_test_1C_1jni(JNIEnv *env, jobject thiz) {
    // TODO: implement test_C_jni()
    std::string jni_result = jni_test_fun2();
    return env->NewStringUTF(jni_result.c_str());
}