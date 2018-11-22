//
// Created by zhangshiyu on 18-11-22.
//

#ifndef JNIOPENCVDEMO_BASEFUNCTION_H
#define JNIOPENCVDEMO_BASEFUNCTION_H

#include <jni.h>
#include "android/log.h"
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#endif //JNIOPENCVDEMO_BASEFUNCTION_H
extern "C" {
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_sharpen(JNIEnv *env,
                                                                       jobject instance,
                                                                       jbyteArray input_,
                                                                       jbyteArray output_,
                                                                       jint width, jint height);
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_sharpenBitmp(
        JNIEnv *env, jclass type, jobject input, jobject output);
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_add(JNIEnv *env, jobject instance,
                                                                   jbyteArray img1_,
                                                                   jbyteArray img2_, jint width,
                                                                   jint height, jdouble alpha,
                                                                   jbyteArray output_);
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_changeLighteness(JNIEnv *env,
                                                                                jobject instance,
                                                                                jbyteArray input_,
                                                                                jbyteArray output_,
                                                                                jint width,
                                                                                jint height,
                                                                                jdouble a,
                                                                                jdouble b);
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_init(JNIEnv *env, jclass type,
                                                                    jstring path_);
}