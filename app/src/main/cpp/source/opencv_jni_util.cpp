//
// Created by zhangshiyu on 18-11-22.
//

#include "opencv_jni_util.h"
cv::Mat convertBitmp2Mat(JNIEnv *env,jobject obj,jobject bitmap) {
    AndroidBitmapInfo infocolor;
    void *pixelscolor;
    int ret;

    if ((ret = AndroidBitmap_getInfo(env, bitmap, &infocolor)) < 0) {

    }

    if (infocolor.format != ANDROID_BITMAP_FORMAT_RGBA_8888) {

    }

    if ((ret = AndroidBitmap_lockPixels(env, bitmap, &pixelscolor)) < 0) {

    }
    cv::Mat test(infocolor.height, infocolor.width, CV_8UC4, (char *) pixelscolor);//BGRA
    cv::Mat bgra;

    cv::Mat bgr;

    cv::Mat rgba;
//转换成BGRA
//cvtColor(test,bgra,CV_RGBA2BGRA);
//转换成BGR
    cvtColor(test, bgr, CV_RGBA2BGR);

    AndroidBitmap_unlockPixels(env, bitmap);
    return bgr;
}
jbyteArray convertMat2byteArray(JNIEnv *env,cv::Mat mat){
    int len=mat.cols*mat.rows*mat.channels();
    jbyteArray output=env->NewByteArray(len);
    jbyte *result= reinterpret_cast<jbyte *>(mat.data);
    env->SetByteArrayRegion(output, 0, len,result);
    ~mat;
    return output;

}