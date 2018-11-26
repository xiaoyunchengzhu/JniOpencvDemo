//
// Created by zhangshiyu on 18-11-25.
//

#ifndef JNIOPENCVDEMO_MORPHOLOGYEX_H
#define JNIOPENCVDEMO_MORPHOLOGYEX_H
#include <jni.h>
#include "android/log.h"
#include "string.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/core.hpp>
#include "opencv2/imgproc/types_c.h"
using namespace cv;
#endif //JNIOPENCVDEMO_MORPHOLOGYEX_H
extern "C"{
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgprocMorphologyEx_morphalogyex(JNIEnv *env,
                                                                                   jclass type,
                                                                                   jbyteArray input_,
                                                                                   jint width,
                                                                                   jint height,
                                                                                   jint operate,
                                                                                   jint element,
                                                                                   jint kernalsize);
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgprocMorphologyEx_init(JNIEnv *env, jclass type,
                                                                           jstring path_);
}