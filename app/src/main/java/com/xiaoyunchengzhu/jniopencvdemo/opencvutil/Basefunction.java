package com.xiaoyunchengzhu.jniopencvdemo.opencvutil;

import android.graphics.Bitmap;

public class Basefunction {


    public static native void init(String path);
    /**
     * 掩码操作,锐化
     * @param input
     * @param output
     * @param width
     * @param height
     */
    public static native void sharpen(byte[] input,byte[] output,int width,int height);
    /**
     * 掩码操作,锐化
     * @param input
     * @param output
     */
    public static native void sharpenBitmp(Bitmap input, Bitmap output);


    /**
     * 图像求和
     * @param img1 图像1
     * @param img2 图像2
     * @param width
     * @param height
     * @param alpha 比重 >0 and <1
     * @param output 输出
     */
    public native void add(byte[] img1,
                           byte[] img2,int width,int height,double alpha,
                           byte[] output);


    /**
     * 改变对比度和亮度
     * @param input
     * @param output
     * @param width
     * @param height
     * @param a 对比度 1 -3
     * @param b 亮度 0 -100
     */
    public native void  changeLighteness(byte[] input,byte[] output,int width,int height,double a,double b);


}
