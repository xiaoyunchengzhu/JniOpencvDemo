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

public class LightnessActivity extends AppCompatActivity {


    SeekBar seekDuibi,seedLightness;
    ImageView result;
    double lightness=0,duibi=0;
    int width = 0;
    int height = 0;
    byte[] source = null;
    Bitmap out;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lightness);
        seedLightness=findViewById(R.id.seek_lightness);
        seekDuibi=findViewById(R.id.seek_duibi);
        result=findViewById(R.id.img2);
        Bitmap bitmap1 = BitmapFactory.decodeResource(getResources(), R.mipmap.img1);
        width = bitmap1.getWidth();
        height = bitmap1.getHeight();
        source = ImgConvert.getBytesByBitmap(bitmap1);

        seekDuibi.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                duibi = (progress / 100.0)*3;
                new Thread(new Runnable() {
                    @Override
                    public void run() {

                        byte[] output = Basefunction.changeLighteness(source, width, height, duibi,lightness);
                        out = ImgConvert.getBitmapByBytes(output, width, height);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                result.setImageBitmap(out);
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
        seedLightness.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                lightness=progress;
                new Thread(new Runnable() {
                    @Override
                    public void run() {

                        byte[] output = Basefunction.changeLighteness(source, width, height, duibi,lightness);
                        out = ImgConvert.getBitmapByBytes(output, width, height);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                result.setImageBitmap(out);
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
