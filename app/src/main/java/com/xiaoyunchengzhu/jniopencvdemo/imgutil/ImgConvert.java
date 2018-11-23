package com.xiaoyunchengzhu.jniopencvdemo.imgutil;

import android.graphics.Bitmap;

import java.nio.ByteBuffer;

/**
 * default config argb8888
 */
public class ImgConvert {

    /**
     * 根据bitmap,获取byte[]
     * @param bitmap
     * @return
     */
    public static byte[] getBytesByBitmap(Bitmap bitmap) {
        ByteBuffer buffer = ByteBuffer.allocate(bitmap.getByteCount());
        bitmap.copyPixelsToBuffer(buffer);
        return buffer.array();
    }

    /**
     * 根据byte[] 获取bitmap
     * @param data
     * @param width
     * @param height
     * @return
     */
    public static Bitmap getBitmapByBytes(byte[] data,int width,int height){
        Bitmap out = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
        out.copyPixelsFromBuffer(ByteBuffer.wrap(data));
        return out;
    }
}
