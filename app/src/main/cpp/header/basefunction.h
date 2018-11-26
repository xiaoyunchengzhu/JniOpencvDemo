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
#include "string.h"
#endif //JNIOPENCVDEMO_BASEFUNCTION_H
const char *path;
extern "C" {
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_sharpen(JNIEnv *env, jclass type,
                                                                       jbyteArray input_,
                                                                       jint width, jint height,
                                                                       jint sharpen);
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_add(JNIEnv *env, jobject instance,
                                                                   jbyteArray img1_,
                                                                   jbyteArray img2_, jint width,
                                                                   jint height, jdouble alpha);
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_changeLighteness(JNIEnv *env,
                                                                                jobject instance,
                                                                                jbyteArray input_,
                                                                                jint width,
                                                                                jint height,
                                                                                jdouble a,
                                                                                jdouble b);
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_init(JNIEnv *env, jclass type,
                                                                    jstring path_);
}