package com.xiaoyunchengzhu.jniopencvdemo;

import android.content.Intent;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.xiaoyunchengzhu.jniopencvdemo.module.imgproc.ErodingAndDilatingActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.base.LightnessActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.base.PlusActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.base.SharpenActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.imgproc.SmoothingActivity;
import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.Basefunction;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("base_opencv");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Basefunction.init(Environment.getExternalStorageDirectory()+"/");
    }

    public void click(View view){
        Class cls=null;
        switch (view.getId()){
            case R.id.btn_1:
                cls= ImgBaseActivity.class;
                break;
            case R.id.btn_2:
                cls= ImgProcActivity.class;
                break;
        }
        if (cls!=null){
            startActivity(new Intent(this,cls));
        }
    }

}
