package com.xiaoyunchengzhu.jniopencvdemo.module.base;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.SeekBar;

import com.xiaoyunchengzhu.jniopencvdemo.R;
import com.xiaoyunchengzhu.jniopencvdemo.imgutil.ImgConvert;
import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.Basefunction;

/**
 * 图像锐化
 */
public class SharpenActivity extends AppCompatActivity {

    ImageView img, img2;
    SeekBar seekBar;
    int width = 0;
    int height = 0;
    byte[] input = null;

    int sharpen = 5;
    Bitmap out;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sharpen);
        img = findViewById(R.id.img);
        img2 = findViewById(R.id.img2);
        seekBar = findViewById(R.id.seek_sharpen);
        Bitmap bitmap1 = BitmapFactory.decodeResource(getResources(), R.mipmap.img1);
        width = bitmap1.getWidth();
        height = bitmap1.getHeight();
        input = ImgConvert.getBytesByBitmap(bitmap1);

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                sharpen = (progress / 10) + 5;
                new Thread(new Runnable() {
                    @Override
                    public void run() {

                        byte[] output = Basefunction.sharpen(input, width, height, sharpen);
                        out = ImgConvert.getBitmapByBytes(output, width, height);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                img2.setImageBitmap(out);
                            }
                        });
                    }
                }).start();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

    }

}
