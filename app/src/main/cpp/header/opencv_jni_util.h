//
// Created by zhangshiyu on 18-11-22.
//

#ifndef JNIOPENCVDEMO_OPENCV_JNI_UTIL_H
#define JNIOPENCVDEMO_OPENCV_JNI_UTIL_H

#endif //JNIOPENCVDEMO_OPENCV_JNI_UTIL_H
#include <opencv2/core/mat.hpp>
#include "stdio.h"
#include <jni.h>
#include "android/log.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h>
#include "android/bitmap.h"
cv::Mat convertBitmp2Mat(JNIEnv *env,jobject obj,jobject bitmap);

jbyteArray convertMat2byteArray(JNIEnv *env,cv::Mat mat);
