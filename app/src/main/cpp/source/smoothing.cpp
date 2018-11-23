
#include "smoothing.h"


JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Smoothing_middleFilter(JNIEnv *env, jobject instance,
                                                                      jbyteArray input_,
                                                                      jint width, jint height,
                                                                         jint alpha) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    cv::Mat image = cv::Mat(height,width,CV_8UC4,(unsigned char *)input);
    const int nChannels = image.channels();
    cv::Mat dst;
    medianBlur(image, dst, alpha);

    int len=width*height*nChannels;
    jbyteArray output=env->NewByteArray(len);
    env->SetByteArrayRegion(output,0,len,(signed char *)dst.data);
    // TODO

    ~image;
    ~dst;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;
}
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Smoothing_blurFilter(JNIEnv *env, jobject instance,
                                                                    jbyteArray input_, jint width,
                                                                    jint height,
                                                                       jint alpha) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    cv::Mat image = cv::Mat(height,width,CV_8UC4,(unsigned char *)input);
    const int nChannels = image.channels();
    cv::Mat dst;
    blur(image, dst, cv::Size(alpha, alpha), cv::Point(-1, -1));

    int len=width*height*nChannels;
    jbyteArray output=env->NewByteArray(len);
    env->SetByteArrayRegion(output,0,len,(signed char *)dst.data);
    // TODO

    ~image;
    ~dst;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;

}
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Smoothing_gaussianFilter(JNIEnv *env,
                                                                        jobject instance,
                                                                        jbyteArray input_,
                                                                        jint width, jint height,
                                                                           jint alpha) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    cv::Mat image = cv::Mat(height,width,CV_8UC4,(unsigned char *)input);
    const int nChannels = image.channels();
    cv::Mat dst;
    GaussianBlur(image, dst, cv::Size(alpha, alpha), 0, 0);

    int len=width*height*nChannels;
    jbyteArray output=env->NewByteArray(len);
    env->SetByteArrayRegion(output,0,len,(signed char *)dst.data);
    // TODO

    ~image;
    ~dst;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;

}
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Smoothing_bilateralFilter(JNIEnv *env,
                                                                         jobject instance,
                                                                         jbyteArray input_,
                                                                         jint width, jint height,
                                                                            jint alpha) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    cv::Mat image = cv::Mat(height,width,CV_8UC4,(unsigned char *)input);
    const int nChannels = image.channels();
    cv::Mat dst;
    bilateralFilter(image, dst, alpha, alpha * 2, alpha / 2);

    int len=width*height*nChannels;
    jbyteArray output=env->NewByteArray(len);
    env->SetByteArrayRegion(output,0,len,(signed char *)dst.data);
    // TODO

    ~image;
    ~dst;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;
}