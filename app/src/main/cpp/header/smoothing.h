//
// Created by zhangshiyu on 18-11-22.
//

#ifndef JNIOPENCVDEMO_NATIVE_LIB_H
#define JNIOPENCVDEMO_NATIVE_LIB_H
#include <jni.h>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#endif //JNIOPENCVDEMO_NATIVE_LIB_H


extern "C" {
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Smoothing_middleFilter(JNIEnv *env,
                                                                         jobject instance,
                                                                         jbyteArray input_,
                                                                         jint width, jint height,
                                                                         jint alpha);
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Smoothing_blurFilter(JNIEnv *env,
                                                                       jobject instance,
                                                                       jbyteArray input_,
                                                                       jint width,
                                                                       jint height,
                                                                       jint alpha);
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Smoothing_gaussianFilter(JNIEnv *env,
                                                                           jobject instance,
                                                                           jbyteArray input_,
                                                                           jint width,
                                                                           jint height,
                                                                           jint alpha);
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Smoothing_bilateralFilter(JNIEnv *env,
                                                                            jobject instance,
                                                                            jbyteArray input_,
                                                                            jint width,
                                                                            jint height,
                                                                            jint alpha);
}