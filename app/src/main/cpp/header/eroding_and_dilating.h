//
// Created by zhangshiyu on 18-11-25.
//

#ifndef JNIOPENCVDEMO_ERODING_AND_DILATING_H
#define JNIOPENCVDEMO_ERODING_AND_DILATING_H
#include <jni.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/core.hpp>
#include "opencv2/imgproc/types_c.h"
using namespace cv;
#endif //JNIOPENCVDEMO_ERODING_AND_DILATING_H
extern "C" {
JNIEXPORT jbyteArray
JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgProcErodingAndDilating_eroding(JNIEnv *env,
                                                                             jclass type,
                                                                             jbyteArray input_,
                                                                             jint width,
                                                                             jint height,
                                                                             jint erosionSize);
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgProcErodingAndDilating_dilation(JNIEnv *env,
                                                                              jclass type,
                                                                              jbyteArray input_,
                                                                              jint width,
                                                                              jint height,
                                                                              jint dilationSize);
}