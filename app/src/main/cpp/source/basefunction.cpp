//
// Created by zhangshiyu on 18-11-22.
//


#include "basefunction.h"
#include "opencv_jni_util.h"
const char *path;
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_sharpen(JNIEnv *env,
                                                                       jobject instance,
                                                                       jbyteArray input_,
                                                                       jbyteArray output_,
                                                                       jint width, jint height) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    jbyte *output = env->GetByteArrayElements(output_, NULL);

// TODO

    cv::Mat myImage = cv::Mat(height, width, CV_8UC3, (uchar *)input).clone();
    char file[128];
    strcpy(file,path);
    strcat(file,"/fuck.jpg");
    __android_log_print(ANDROID_LOG_INFO,"jni","path %s",file);
    cv::imwrite(file,myImage);
    cv::Mat Result;
    CV_Assert(myImage.depth() == CV_8U);  // 仅接受uchar图像

    Result.create(myImage.size(), myImage.type());
    const int nChannels = myImage.channels();

    for (int j = 1; j < myImage.rows - 1; ++j) {
        const uchar *previous = myImage.ptr<uchar>(j - 1);
        const uchar *current = myImage.ptr<uchar>(j);
        const uchar *next = myImage.ptr<uchar>(j + 1);

        uchar *output = Result.ptr<uchar>(j);

        for (int i = nChannels; i < nChannels * (myImage.cols - 1); ++i) {
            *output++ = cv::saturate_cast<uchar>(5 * current[i]
                                                 - current[i - nChannels] - current[i + nChannels] -
                                                 previous[i] - next[i]);
        }
    }

    Result.row(0).setTo(cv::Scalar(0));
    Result.row(Result.rows - 1).setTo(cv::Scalar(0));
    Result.col(0).setTo(cv::Scalar(0));
    Result.col(Result.cols - 1).setTo(cv::Scalar(0));



    unsigned char *data1=Result.data;
    jbyte *data = reinterpret_cast<jbyte *>(Result.data);
    env->SetByteArrayRegion(output_, 0, width * height, data);
    env->ReleaseByteArrayElements(input_, input, 0);
//    env->ReleaseByteArrayElements(output_, output, 0);
}

JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_sharpenBitmp(
        JNIEnv *env, jclass type, jobject input, jobject output) {



    // TODO
    cv::Mat myImage = convertBitmp2Mat(env,type,input);
    cv::Mat Result;
    CV_Assert(myImage.depth() == CV_8U);  // 仅接受uchar图像

    Result.create(myImage.size(),myImage.type());
    const int nChannels = myImage.channels();

    for(int j = 1 ; j < myImage.rows-1; ++j)
    {
        const uchar* previous = myImage.ptr<uchar>(j - 1);
        const uchar* current  = myImage.ptr<uchar>(j    );
        const uchar* next     = myImage.ptr<uchar>(j + 1);

        uchar* output = Result.ptr<uchar>(j);

        for(int i= nChannels;i < nChannels*(myImage.cols-1); ++i)
        {
            *output++ = cv::saturate_cast<uchar>(5*current[i]
                                             -current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
        }
    }

    Result.row(0).setTo(cv::Scalar(0));
    Result.row(Result.rows-1).setTo(cv::Scalar(0));
    Result.col(0).setTo(cv::Scalar(0));
    Result.col(Result.cols-1).setTo(cv::Scalar(0));

    char file[128];
    strcpy(file,path);
    strcat(file,"/fuck.jpg");
    __android_log_print(ANDROID_LOG_INFO,"jni","path %s",file);
    cv::imwrite(file,Result);


}
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_add(JNIEnv *env, jobject instance,
                                                                   jbyteArray img1_,
                                                                   jbyteArray img2_, jint width,
                                                                   jint height, jdouble alpha,
                                                                   jbyteArray output_) {
    jbyte *img1 = env->GetByteArrayElements(img1_, NULL);
    jbyte *img2 = env->GetByteArrayElements(img2_, NULL);
    jbyte *output = env->GetByteArrayElements(output_, NULL);

// TODO

    env->ReleaseByteArrayElements(img1_, img1, 0);
    env->ReleaseByteArrayElements(img2_, img2, 0);
    env->ReleaseByteArrayElements(output_, output, 0);
}

JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_changeLighteness(JNIEnv *env,
                                                                                jobject instance,
                                                                                jbyteArray input_,
                                                                                jbyteArray output_,
                                                                                jint width,
                                                                                jint height,
                                                                                jdouble a,
                                                                                jdouble b) {
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    jbyte *output = env->GetByteArrayElements(output_, NULL);

// TODO

    env->ReleaseByteArrayElements(input_, input, 0);
    env->ReleaseByteArrayElements(output_, output, 0);
}

JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_init(JNIEnv *env, jclass type,
                                                                    jstring path_) {
    path = env->GetStringUTFChars(path_, 0);
    // TODO

//    env->ReleaseStringUTFChars(path_, path);
}