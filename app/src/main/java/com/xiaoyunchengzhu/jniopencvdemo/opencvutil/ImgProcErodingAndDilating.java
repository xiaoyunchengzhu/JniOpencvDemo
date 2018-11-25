package com.xiaoyunchengzhu.jniopencvdemo.opencvutil;

/**
 * 腐蚀和膨胀
 */
public class ImgProcErodingAndDilating {

    /**
     * 腐蚀
     * @param input
     * @param width
     * @param height
     * @param erosionSize
     * @return
     */
    public native static byte[] eroding(byte[] input,int width,int height,int erosionSize);

    /**
     * 膨胀
     * @param input
     * @param width
     * @param height
     * @param dilationSize
     * @return
     */
    public native static byte[] dilation(byte[] input,int width,int height,int dilationSize);
}
