//
// Created by zhangshiyu on 18-11-25.
//

#include "morphologyex.h"
#include "opencv_jni_util.h"
int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
//int const max_kernel_size = 21;
const char  *file;

JNIEXPORT jbyteArray JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgprocMorphologyEx_morphalogyex(JNIEnv *env,
                                                                                   jclass type,
                                                                                   jbyteArray input_,
                                                                                   jint width,
                                                                                   jint height,
                                                                                   jint operate,
                                                                                   jint element,
                                                                                   jint kernalsize) {
    morph_operator=operate;
    morph_elem=element;
    morph_size=kernalsize;
    jbyte *input = env->GetByteArrayElements(input_, NULL);
    // TODO
    Mat src=cv::Mat(height,width,CV_8UC4,input);

    Mat dst=src.clone();
    // TODO
    // 由于 MORPH_X的取值范围是: 2,3,4,5 和 6
    int operation = morph_operator + 2;

    Mat elementMat = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );

    /// 运行指定形态学操作
    morphologyEx( dst, dst, operation, elementMat );
    char img[150];
    strcpy(img,file);
    strcat(img,"fuck9.jpg");
    imwrite(img,dst);

    jbyteArray output=convertMat2byteArray(env,dst);
    ~src;
    ~dst;
    ~elementMat;
    env->ReleaseByteArrayElements(input_, input, 0);
    return output;
}
JNIEXPORT void JNICALL
Java_com_xiaoyunchengzhu_jniopencvdemo_opencvutil_ImgprocMorphologyEx_init(JNIEnv *env, jclass type,
                                                                           jstring path_) {
    file = env->GetStringUTFChars(path_, 0);

    // TODO


//    env->ReleaseStringUTFChars(path_, path);
}