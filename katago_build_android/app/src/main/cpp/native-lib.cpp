#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_katago6_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_katago6_katago_getStdoutFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement getStdoutFromJNI()
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_katago6_katago_StartEngine(JNIEnv *env, jobject thiz, jstring weight) {
    // TODO: implement StartEngine()
    const char* str;
    str = env->GetStringUTFChars(weight, NULL);
    std::string weightsfile = str;
    env->ReleaseStringUTFChars(weight, str);






}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_katago6_katago_SendGTP(JNIEnv *env, jobject thiz, jstring cmd) {
    // TODO: implement SendGTP()
}
