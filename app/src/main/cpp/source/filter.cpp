#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Filter_middleFilter(JNIEnv *env, jobject instance,
                                                                      jbyteArray input_,
                                                                      jbyteArray output_,
                                                                      jint width, jint height) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    jbyte *output = env->GetByteArrayElements(output_, NULL);

    // TODO

    env->ReleaseByteArrayElements(input_, input, 0);
    env->ReleaseByteArrayElements(output_, output, 0);
}extern "C"
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Filter_blurFilter(JNIEnv *env, jobject instance,
                                                                    jbyteArray input_,
                                                                    jbyteArray output_, jint width,
                                                                    jint height) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    jbyte *output = env->GetByteArrayElements(output_, NULL);

    // TODO

    env->ReleaseByteArrayElements(input_, input, 0);
    env->ReleaseByteArrayElements(output_, output, 0);
}extern "C"
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Filter_gaussianFilter(JNIEnv *env,
                                                                        jobject instance,
                                                                        jbyteArray input_,
                                                                        jbyteArray output_,
                                                                        jint width, jint height) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    jbyte *output = env->GetByteArrayElements(output_, NULL);

    // TODO

    env->ReleaseByteArrayElements(input_, input, 0);
    env->ReleaseByteArrayElements(output_, output, 0);
}extern "C"
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Filter_bilateralFilter(JNIEnv *env,
                                                                         jobject instance,
                                                                         jbyteArray input_,
                                                                         jbyteArray output_,
                                                                         jint width, jint height) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    jbyte *output = env->GetByteArrayElements(output_, NULL);

    // TODO

    env->ReleaseByteArrayElements(input_, input, 0);
    env->ReleaseByteArrayElements(output_, output, 0);
}