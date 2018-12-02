//
// Created by zhangshiyu on 18-11-22.
//


#include "../header/basefunction.h"
#include "../header/opencv_jni_util.h"
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_sharpen(JNIEnv *env, jclass type,
                                                                       jbyteArray input_,
                                                                       jint width, jint height,
                                                                       jint sharpen) {
    unsigned char *input = (unsigned char *)env->GetByteArrayElements(input_, NULL);
    // TODO
    cv::Mat myImage=cv::Mat(height,width,CV_8UC4,input);
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
            *output++ = cv::saturate_cast<uchar>(sharpen*current[i]
                                                 -current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
        }
    }

    Result.row(0).setTo(cv::Scalar(0));
    Result.row(Result.rows-1).setTo(cv::Scalar(0));
    Result.col(0).setTo(cv::Scalar(0));
    Result.col(Result.cols-1).setTo(cv::Scalar(0));


    jbyteArray output=convertMat2byteArray(env,Result);

    ~myImage;
    env->ReleaseByteArrayElements(input_,(signed char *)input,0);
    return output;
}

JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_add(JNIEnv *env, jobject instance,
                                                                   jbyteArray img1_,
                                                                   jbyteArray img2_, jint width,
                                                                   jint height, jdouble alpha
                                                                   ) {
    unsigned char *img1 = (unsigned char *)env->GetByteArrayElements(img1_, NULL);
    unsigned char *img2 = (unsigned char *)env->GetByteArrayElements(img2_, NULL);


// TODO

     double beta;

    cv::Mat src1=cv::Mat(height,width,CV_8UC4,img1);
    cv::Mat src2=cv::Mat(height,width,CV_8UC4,img2);
    cv::Mat dst;
    const int nChannels = src1.channels();

    if( !src1.data ) { printf("Error loading src1 \n"); return nullptr; }
    if( !src2.data ) { printf("Error loading src2 \n"); return nullptr; }

    beta = ( 1.0 - alpha );
    cv::addWeighted( src1, alpha, src2, beta, 0.0, dst);

    jbyteArray output=convertMat2byteArray(env,dst);


    ~src1;
    ~src2;
    env->ReleaseByteArrayElements(img1_, (signed char *)img1, 0);
    env->ReleaseByteArrayElements(img2_, (signed char *)img2, 0);
    return output;
}

JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_changeLighteness(JNIEnv *env,
                                                                                jobject instance,
                                                                                jbyteArray input_,
                                                                                jint width,
                                                                                jint height,
                                                                                jdouble alpha,
                                                                                jdouble beta) {
    unsigned char *input = (unsigned char *)env->GetByteArrayElements(input_, NULL);

    cv::Mat image = cv::Mat(height,width,CV_8UC4,input);
    const int nChannels = image.channels();
    cv::Mat new_image = cv::Mat::zeros( image.size(), image.type() );
    image.convertTo(new_image, -1, alpha, beta);



    jbyteArray output=convertMat2byteArray(env,new_image);

    ~image;
    env->ReleaseByteArrayElements(input_, (signed char *)input, 0);
    return output;
}

JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_Basefunction_init(JNIEnv *env, jclass type,
                                                                    jstring path_) {
    path = env->GetStringUTFChars(path_, 0);
    // TODO

//    env->ReleaseStringUTFChars(path_, path);
}

