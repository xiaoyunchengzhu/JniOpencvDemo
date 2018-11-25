package com.xiaoyunchengzhu.jniopencvdemo.module.imgproc;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.SeekBar;

import com.xiaoyunchengzhu.jniopencvdemo.R;
import com.xiaoyunchengzhu.jniopencvdemo.imgutil.ImgConvert;
import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.ImgProcErodingAndDilating;

/**
 * 腐蚀和膨胀
 */
public class ErodingAndDilatingActivity extends AppCompatActivity implements SeekBar.OnSeekBarChangeListener{

    ImageView img1,img2;
    SeekBar seekBar1,seekBar2;

    int width = 0;
    int height = 0;
    byte[] input = null;

    Bitmap out1,out2;
    int erosionSize,dilationSize;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_eroding_and_dilating);
        initview();
        seekBar1.setOnSeekBarChangeListener(this);
        seekBar2.setOnSeekBarChangeListener(this);
        Bitmap bitmap1 = BitmapFactory.decodeResource(getResources(), R.mipmap.img1);
        width = bitmap1.getWidth();
        height = bitmap1.getHeight();
        input = ImgConvert.getBytesByBitmap(bitmap1);

        seekBar1.setOnSeekBarChangeListener(this);
        seekBar2.setOnSeekBarChangeListener(this);
    }
    private void initview(){
        img1=findViewById(R.id.img1);
        img2=findViewById(R.id.img2);
        seekBar1=findViewById(R.id.seek_1);
        seekBar2=findViewById(R.id.seek_2);
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        int value=(21*progress / 100);
        switch (seekBar.getId()){
            case R.id.seek_1:
                /**
                 * 腐蚀
                 */
                erosionSize = value;
                new Thread(new Runnable() {
                    @Override
                    public void run() {

                        byte[] output = ImgProcErodingAndDilating.eroding(input,width,height,erosionSize);
                        out1 = ImgConvert.getBitmapByBytes(output, width, height);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                img1.setImageBitmap(out1);
                            }
                        });
                    }
                }).start();
                break;
            case R.id.seek_2:
                /**
                 * 膨胀
                 */
                dilationSize = value;
                new Thread(new Runnable() {
                    @Override
                    public void run() {

                        byte[] output = ImgProcErodingAndDilating.dilation(input,width,height,dilationSize);
                        out2 = ImgConvert.getBitmapByBytes(output, width, height);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                img2.setImageBitmap(out2);
                            }
                        });
                    }
                }).start();
                break;
        }
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {

    }
}
