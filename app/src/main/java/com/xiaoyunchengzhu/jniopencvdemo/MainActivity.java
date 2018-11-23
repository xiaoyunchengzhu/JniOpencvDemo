package com.xiaoyunchengzhu.jniopencvdemo;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.xiaoyunchengzhu.jniopencvdemo.imgutil.ImgConvert;
import com.xiaoyunchengzhu.jniopencvdemo.module.LightnessActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.PlusActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.SharpenActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.SmoothingActivity;
import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.Basefunction;

import java.io.ByteArrayOutputStream;
import java.nio.ByteBuffer;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("base_opencv");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Basefunction.init(Environment.getExternalStorageDirectory()+"");
    }

    public void click(View view){
        Class cls=null;
        switch (view.getId()){
            case R.id.btn_sharpen:
                cls= SharpenActivity.class;
                break;
            case R.id.btn_plus:
                cls= PlusActivity.class;
                break;
            case R.id.btn_lightness:
                cls= LightnessActivity.class;
                break;
            case R.id.btn_smoothing:
                cls= SmoothingActivity.class;
                break;
        }
        if (cls!=null){
            startActivity(new Intent(this,cls));
        }
    }

}
