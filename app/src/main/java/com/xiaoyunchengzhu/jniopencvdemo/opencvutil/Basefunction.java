package com.xiaoyunchengzhu.jniopencvdemo.opencvutil;

import android.graphics.Bitmap;

public class Basefunction {


    public static native void init(String path);

    /**
     * 掩码操作，锐化
     * @param input
     * @param width
     * @param height
     * @return 锐化后的数据
     */
    public static native byte[] sharpen(byte[] input,int width,int height,int sharpen);



    /**
     * 图像求和
     * @param img1 图像1
     * @param img2 图像2
     * @param width
     * @param height
     * @param alpha 比重 >0 and <1
     * @return 求和后的数据
     */
    public static native byte[] add(byte[] img1,
                           byte[] img2,int width,int height,double alpha
                           );


    /**
     * 改变对比度和亮度
     * @param input
     * @param width
     * @param height
     * @param a 对比度 1.0 -3.0
     * @param b 亮度 0 -100
     * @return 改变后的数据
     */
    public static native byte[]  changeLighteness(byte[] input,int width,int height,double a,double b);


}
