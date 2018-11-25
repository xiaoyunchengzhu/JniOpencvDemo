package com.xiaoyunchengzhu.jniopencvdemo.module.imgproc;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.SeekBar;

import com.xiaoyunchengzhu.jniopencvdemo.R;
import com.xiaoyunchengzhu.jniopencvdemo.imgutil.ImgConvert;
import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.ImgProcSmoothing;

/**
 * 滤波 ，平滑处理,仅对左侧脸部局部区域滤波，如果想改区域，则可直接进入源码修改选择区域，或者为native 方法增加区域参数。
 */
public class SmoothingActivity extends AppCompatActivity implements SeekBar.OnSeekBarChangeListener{

    ImageView img1,img2,img3;
    SeekBar seekBar1,seekBar2,seekBar3;

    int width = 0;
    int height = 0;
    byte[] input = null;

    Bitmap out1,out2,out3;
    int alpha1,alpha2,alpha3;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_smoothing);
        initview();
        seekBar1.setOnSeekBarChangeListener(this);
        seekBar2.setOnSeekBarChangeListener(this);
        seekBar3.setOnSeekBarChangeListener(this);
        Bitmap bitmap1 = BitmapFactory.decodeResource(getResources(), R.mipmap.img4);
        width = bitmap1.getWidth();
        height = bitmap1.getHeight();
        input = ImgConvert.getBytesByBitmap(bitmap1);
    }
    private void initview(){
        img1=findViewById(R.id.img1);
        img2=findViewById(R.id.img2);
        img3=findViewById(R.id.img3);

        seekBar1=findViewById(R.id.seek_1);
        seekBar2=findViewById(R.id.seek_2);
        seekBar3=findViewById(R.id.seek_3);


    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        int value=31*progress/100;
        if (value%2==0){
            value=-1;
        }
        if (value<=0){
            value=1;
        }
       switch (seekBar.getId()){
           case R.id.seek_1:
               alpha1=value;

               middleFilter();
               break;
           case R.id.seek_2:
               alpha2=value;
               blurFilter();
               break;
           case R.id.seek_3:
               alpha3=value;
               gaussianFilter();
               break;
       }

    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {

    }

    private void middleFilter(){
        new Thread(new Runnable() {
            @Override
            public void run() {

                byte[] output = ImgProcSmoothing.middleFilter(input,width,height,alpha1);
                out1 = ImgConvert.getBitmapByBytes(output, width, height);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        img1.setImageBitmap(out1);
                    }
                });
            }
        }).start();
    }
    private void blurFilter(){
        new Thread(new Runnable() {
            @Override
            public void run() {

                byte[] output = ImgProcSmoothing.blurFilter(input,width,height,alpha2);
                out2 = ImgConvert.getBitmapByBytes(output, width, height);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        img2.setImageBitmap(out2);
                    }
                });
            }
        }).start();
    }
    private void gaussianFilter(){
        new Thread(new Runnable() {
            @Override
            public void run() {

                byte[] output = ImgProcSmoothing.gaussianFilter(input,width,height,alpha3);
                out3 = ImgConvert.getBitmapByBytes(output, width, height);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        img3.setImageBitmap(out3);
                    }
                });
            }
        }).start();
    }

}
