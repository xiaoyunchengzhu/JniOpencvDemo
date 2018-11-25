package com.xiaoyunchengzhu.jniopencvdemo;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.xiaoyunchengzhu.jniopencvdemo.module.base.LightnessActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.base.PlusActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.base.SharpenActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.imgproc.ErodingAndDilatingActivity;
import com.xiaoyunchengzhu.jniopencvdemo.module.imgproc.SmoothingActivity;

public class ImgProcActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_img_proc);
    }
    public void click(View view){
        Class cls=null;
        switch (view.getId()){
            case R.id.btn_1:
                cls= SmoothingActivity.class;
                break;
            case R.id.btn_2:
                cls= ErodingAndDilatingActivity.class;
                break;
            case R.id.btn_3:

                break;
        }
        if (cls!=null){
            startActivity(new Intent(this,cls));
        }
    }
}
