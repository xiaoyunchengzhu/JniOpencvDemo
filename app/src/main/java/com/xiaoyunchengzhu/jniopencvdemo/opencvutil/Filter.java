package com.xiaoyunchengzhu.jniopencvdemo.opencvutil;

/**
 * 滤波处理
 */
public class Filter {


    /**
     * 中值滤波
     * @param input
     * @param output
     * @param width
     * @param height
     */
    public native void middleFilter(byte[] input,byte[] output,int width,int height);

    /**
     * 归一化滤波
     * @param input
     * @param output
     * @param width
     * @param height
     */
    public native void blurFilter(byte[] input,byte[] output,int width,int height);

    /**
     * 高斯滤波
     * @param input
     * @param output
     * @param width
     * @param height
     */
    public native void gaussianFilter(byte[] input,byte[] output,int width,int height);

    /**
     * 双边滤波
     * @param input
     * @param output
     * @param width
     * @param height
     */
    public native void bilateralFilter(byte[] input,byte[] output,int width,int height);
}
