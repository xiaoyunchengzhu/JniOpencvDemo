package com.xiaoyunchengzhu.jniopencvdemo.module.imgproc;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.SeekBar;

import com.xiaoyunchengzhu.jniopencvdemo.R;
import com.xiaoyunchengzhu.jniopencvdemo.imgutil.ImgConvert;
import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.ImgProcErodingAndDilating;
import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.ImgprocMorphologyEx;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;

public class MorphologyExActivity extends AppCompatActivity implements SeekBar.OnSeekBarChangeListener{

    SeekBar seekBaroperate,seekBarElement,seekBarKernalsize;
    ImageView img1;

    int width = 0;
    int height = 0;
    byte[] input = null;

    Bitmap out;
    int operate,element,kernalsize;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_morphology_ex);
        ImgprocMorphologyEx.init(Environment.getExternalStorageDirectory()+"/");
        initview();
        Bitmap bitmap1 = BitmapFactory.decodeResource(getResources(), R.mipmap.img1);
        width = bitmap1.getWidth();
        height = bitmap1.getHeight();
        Bitmap f=BitmapFactory.decodeFile(Environment.getExternalStorageDirectory()+"/fuck5.jpg");
        input = ImgConvert.getBytesByBitmap(bitmap1);
        seekBaroperate.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                operate=progress;
                meature();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
        seekBarElement.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                element=progress;
                meature();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
        seekBarKernalsize.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                kernalsize=progress;
                meature();
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        img1.setImageBitmap(f);
//        byte[] bytesByBitmap = ImgConvert.getBytesByBitmap(f);
//        StringBuffer d=new StringBuffer();
//        for (int i=0;i<bytesByBitmap.length;i++){
//            d.append(bytesByBitmap[i]+",");
//        }
//
//        Log.i("datafuck:","row byte"+bytesByBitmap.length+"\n,buffer data:"+d.toString());
    }

    private void initview(){
        seekBaroperate=findViewById(R.id.seek_1);
        seekBarElement=findViewById(R.id.seek_2);
        seekBarKernalsize=findViewById(R.id.seek_3);
        img1=findViewById(R.id.img1);
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        switch (seekBar.getId()){
            case R.id.seek_1:
                operate=progress;

                break;
            case R.id.seek_2:
                element=progress;
                break;
            case R.id.seek_3:
                kernalsize=progress;
                break;
        }

    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {

    }

    private void meature(){
        new Thread(new Runnable() {
            @Override
            public void run() {

                byte[] output = ImgprocMorphologyEx.morphalogyex(input,width,height,operate,element,kernalsize);
//
                out=null;
                out = ImgConvert.getBitmapByBytes(output, width, height);
//                write(out);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        img1.setImageBitmap(out);
                    }
                });
            }
        }).start();
    }

    public void write(Bitmap bm){
        try {
            FileOutputStream outputStream=new FileOutputStream(new File(Environment.getExternalStorageDirectory()+"/fuck10.jpg"));
            bm.compress(Bitmap.CompressFormat.JPEG, 100, outputStream);
            outputStream.flush();
            outputStream.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
