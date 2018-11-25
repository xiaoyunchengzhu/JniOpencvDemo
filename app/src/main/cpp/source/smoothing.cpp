
#include "smoothing.h"


JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgProcSmoothing_middleFilter(JNIEnv *env, jobject instance,
                                                                      jbyteArray input_,
                                                                      jint width, jint height,
                                                                         jint alpha) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    cv::Mat inputimg = cv::Mat(height,width,CV_8UC4,(unsigned char *)input);
    cv::Mat image=inputimg.clone();
    const int nChannels = image.channels();
    cv::Mat dst=cv::Mat(image, cv::Rect(0, image.rows / 3, image.cols / 3, image.rows / 2));
    medianBlur(dst, dst, alpha);

    int len=width*height*nChannels;
    jbyteArray output=env->NewByteArray(len);
    env->SetByteArrayRegion(output,0,len,(signed char *)image.data);
    // TODO

    ~inputimg;
    ~image;
    ~dst;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;
}
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgProcSmoothing_blurFilter(JNIEnv *env, jobject instance,
                                                                    jbyteArray input_, jint width,
                                                                    jint height,
                                                                       jint alpha) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    cv::Mat inputimg = cv::Mat(height,width,CV_8UC4,(unsigned char *)input);
    cv::Mat image=inputimg.clone();
    const int nChannels = image.channels();
    cv::Mat dst=cv::Mat(image, cv::Rect(0, image.rows / 3, image.cols / 3, image.rows / 2));
    blur(dst, dst, cv::Size(alpha, alpha), cv::Point(-1, -1));

    int len=width*height*nChannels;
    jbyteArray output=env->NewByteArray(len);
    env->SetByteArrayRegion(output,0,len,(signed char *)image.data);
    // TODO
    ~inputimg;
    ~image;
    ~dst;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;

}
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgProcSmoothing_gaussianFilter(JNIEnv *env,
                                                                        jobject instance,
                                                                        jbyteArray input_,
                                                                        jint width, jint height,
                                                                           jint alpha) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    cv::Mat inputimg = cv::Mat(height,width,CV_8UC4,(unsigned char *)input);
    cv::Mat image=inputimg.clone();
    const int nChannels = image.channels();
    cv::Mat dst=cv::Mat(image, cv::Rect(0, image.rows / 3, image.cols / 3, image.rows / 2));
    GaussianBlur(dst, dst, cv::Size(alpha, alpha), 0, 0);

    int len=width*height*nChannels;
    jbyteArray output=env->NewByteArray(len);
    env->SetByteArrayRegion(output,0,len,(signed char *)image.data);
    // TODO

    ~inputimg;
    ~image;
    ~dst;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;

}
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgProcSmoothing_bilateralFilter(JNIEnv *env,
                                                                         jobject instance,
                                                                         jbyteArray input_,
                                                                         jint width, jint height,
                                                                            jint alpha) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    cv::Mat inputimg = cv::Mat(height,width,CV_8UC4,(unsigned char *)input);
    cv::Mat image=inputimg.clone();
    const int nChannels = image.channels();
    cv::Mat dst=cv::Mat(image, cv::Rect(0, image.rows / 3, image.cols / 3, image.rows / 2));
    bilateralFilter(dst, dst, alpha, alpha * 2, alpha / 2);

    int len=width*height*nChannels;
    jbyteArray output=env->NewByteArray(len);
    env->SetByteArrayRegion(output,0,len,(signed char *)image.data);
    // TODO

    ~inputimg;
    ~image;
    ~dst;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;
}