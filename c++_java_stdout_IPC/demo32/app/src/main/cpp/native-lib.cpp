#include <jni.h>
#include <string>
#include "include/test.h"
#include "include/cmdline.h"
#include "include/katago.h"
#include "include/time_thread.h"
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <chrono>             // std::chrono::seconds
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable, std::cv_status
#include <time.h>
#include <sstream>
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


extern "C"
JNIEXPORT jint JNICALL
Java_com_example_demo3_MainActivity_test2(JNIEnv *env, jobject thiz, jint agrc, jobjectArray argv) {
    // TODO: implement test2()
    int res = test_main(agrc, reinterpret_cast<string *>(argv));
    return res;
}


extern "C"
JNIEXPORT jint JNICALL
Java_com_example_demo3_katago_test_1mian2023(JNIEnv *env, jobject thiz, jint i, jobjectArray argv) {
    // TODO: implement test_mian2023()
    int res = test_main(i, reinterpret_cast<string *>(argv));
    return res;

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demo3_katago_getStdoutFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement getStdoutFromJNI()
    std::string hello = "Hello from C++";
//
//    std::condition_variable cv;
//    std::mutex mtx;
//    std::unique_lock<std::mutex> lck(mtx);
//    while (cv.wait_for(lck,std::chrono::seconds(2))==std::cv_status::timeout)
//    {
//        // std::cout << '.' << std::endl;
//        time_t now = time(NULL);
//        tm* tm_t = localtime(&now);
//        std::stringstream ss;
//        ss << "year:" << tm_t->tm_year + 1900 << " month:" << tm_t->tm_mon + 1 << " day:" << tm_t->tm_mday
//           << " hour:" << tm_t->tm_hour << " minute:" << tm_t->tm_min << " second:" << tm_t->tm_sec;
//        std::cout << ss.str() <<std::endl;;
//
//    }



//    return env->NewStringUTF(hello.c_str());
    return  env->NewStringUTF(getStdout().c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demo3_MainActivity_test2023(JNIEnv *env, jobject thiz) {
    // TODO: implement test2023()
    std::string hello = "Hello from C++";
    std::cout << "hello" <<std::endl;
//    env->NewStringUTF(getStdout().c_str());
   return env->NewStringUTF(getStdout().c_str());
//   return env->NewStringUTF(testOut().c_str());


}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demo3_MainActivity_time_1thread(JNIEnv *env, jobject thiz) {
    // TODO: implement time_thread()
    time_test ();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_demo3_katago_time_1thread_1katago(JNIEnv * env, jobject thiz) {
    // TODO: implement time_thread_katago()
    time_test ();
}