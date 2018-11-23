package com.xiaoyunchengzhu.jniopencvdemo.opencvutil;

/**
 * 滤波，平滑处理
 */
public class Smoothing {


    /**
     * 中值滤波
     * @param input
     * @param width
     * @param height
     * @return 滤波结果
     */
    public static native byte[]  middleFilter(byte[] input,int width,int height,int alpha);

    /**
     * 归一化滤波
     * @param input
     * @param width
     * @param height
     * @return 滤波结果
     */
    public static native byte[] blurFilter(byte[] input,int width,int height,int alpha);

    /**
     * 高斯滤波
     * @param input
     * @param width
     * @param height
     * @return 滤波结果
     */
    public static native byte[] gaussianFilter(byte[] input,int width,int height,int alpha);

    /**
     * 双边滤波
     * @param input
     * @param width
     * @param height
     * @return 滤波结果
     */
    public static native byte[] bilateralFilter(byte[] input,int width,int height,int alpha);
}
