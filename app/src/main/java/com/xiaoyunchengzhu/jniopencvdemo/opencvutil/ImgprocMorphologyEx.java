package com.xiaoyunchengzhu.jniopencvdemo.opencvutil;
/**
 * 更多形态学变换，腐蚀膨胀的延伸，结合
 */
public class ImgprocMorphologyEx {

    public static native void init(String path);
    /**
     * 形态变换
     * @param input
     * @param width
     * @param height
     * @param operate 操作 0:Opening，1:Closing,2:Gradient,3:Top Hat,4:Black Hat
     * @param element 0：Rect，1：cross,2:Ellipse
     * @param kernalsize Kernel size
     * @return
     */
    public native static  byte[] morphalogyex(byte[] input,int width,int height,int operate,int element,int kernalsize);
}
