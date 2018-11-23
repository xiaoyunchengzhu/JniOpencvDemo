package com.xiaoyunchengzhu.jniopencvdemo.module;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.SeekBar;

import com.xiaoyunchengzhu.jniopencvdemo.R;
import com.xiaoyunchengzhu.jniopencvdemo.imgutil.ImgConvert;
import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.Basefunction;


/**
 * 图像合并必须相同尺寸的图才能合并，如果尺寸不同，那么可以转换尺寸相同。同尺寸处理，此处省略。
 */
public class PlusActivity extends AppCompatActivity {


    ImageView combine;
    ImageView com1;
    ImageView com2;
    SeekBar seekCombine;
    double currentAlpha = 0.0;
    int width = 0;
    int height = 0;
    byte[] img1 = null;
    byte[] img2 = null;
    Bitmap out;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_plus);
        initview();
        Bitmap bitmap1 = BitmapFactory.decodeResource(getResources(), R.mipmap.img1);
        Bitmap bitmap2 = BitmapFactory.decodeResource(getResources(), R.mipmap.img2);
        width = bitmap1.getWidth();
        height = bitmap1.getHeight();
        img1 = ImgConvert.getBytesByBitmap(bitmap1);
        img2 = ImgConvert.getBytesByBitmap(bitmap2);
        seekCombine.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                currentAlpha = progress / 100.0;
                new Thread(new Runnable() {
                    @Override
                    public void run() {

                        byte[] combinebytes = Basefunction.add(img1, img2, width, height, currentAlpha);
                        out = ImgConvert.getBitmapByBytes(combinebytes, width, height);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                combine.setImageBitmap(out);
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

    private void initview() {
        combine = findViewById(R.id.img_combine);
        com1 = findViewById(R.id.img_com1);
        com2 = findViewById(R.id.img_com2);
        seekCombine = findViewById(R.id.seek_combine);
    }


}
