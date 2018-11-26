//
// Created by zhangshiyu on 18-11-25.
//

#include "eroding_and_dilating.h"
#include "opencv_jni_util.h"
int erosion_elem = 1;
int erosion_size = 0;
int dilation_elem = 1;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;


JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgProcErodingAndDilating_eroding(JNIEnv *env,
                                                                             jclass type,
                                                                             jbyteArray input_,
                                                                             jint width,
                                                                             jint height,
                                                                             jint erosionSize) {
    erosion_size=erosionSize;
    if (erosion_size>max_kernel_size){
        erosion_size=max_kernel_size;
    }
    unsigned char *input = (unsigned char *)env->GetByteArrayElements(input_, NULL);
    // TODO
    Mat src=cv::Mat(height,width,CV_8UC4,input);
    const int nChannels = src.channels();
    Mat erosion_dst;
    // TODO

    int erosion_type;
    if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
    else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
    else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

    Mat element = getStructuringElement( erosion_type,
                                         Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                         Point( erosion_size, erosion_size ) );

    /// 腐蚀操作
    erode( src, erosion_dst, element );


    jbyteArray output=convertMat2byteArray(env,erosion_dst);
    ~src;
    ~element;
    env->ReleaseByteArrayElements(input_, (signed char *)input, 0);
    return output;
}
JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgProcErodingAndDilating_dilation(JNIEnv *env,
                                                                              jclass type,
                                                                              jbyteArray input_,
                                                                              jint width,
                                                                              jint height,
                                                                              jint dilationSize) {
    dilation_size=dilationSize;
    if (dilation_size>max_kernel_size){
        dilation_size=max_kernel_size;
    }
    unsigned char *input = (unsigned char *)env->GetByteArrayElements(input_, NULL);
    // TODO
    Mat src=cv::Mat(height,width,CV_8UC4,input);
    const int nChannels = src.channels();

    Mat dilation_dst;
    int dilation_type;
    if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
    else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
    else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

    Mat element = getStructuringElement( dilation_type,
                                         Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                         Point( dilation_size, dilation_size ) );
    ///膨胀操作
    dilate( src, dilation_dst, element );

    // TODO
    jbyteArray output=convertMat2byteArray(env,dilation_dst);

    ~src;
    ~element;
    env->ReleaseByteArrayElements(input_, (signed char *)input, 0);
    return output;
}