package com.xiaoyunchengzhu.jniopencvdemo;

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

import com.xiaoyunchengzhu.jniopencvdemo.opencvutil.Basefunction;

import java.io.ByteArrayOutputStream;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("base_opencv");
    }
    ImageView img,img2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Basefunction.init(Environment.getExternalStorageDirectory()+"");
        // Example of a call to a native method
         img=findViewById(R.id.img);
         img2=findViewById(R.id.img2);

    }
    Bitmap out;
    public void click(View view){

        new Thread(new Runnable() {
            @Override
            public void run() {
                Drawable drawable = img.getDrawable();
                BitmapDrawable drawable1= (BitmapDrawable) drawable;
                Bitmap bitmap = drawable1.getBitmap();
                Basefunction.sharpenBitmp(bitmap,null);
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        img2.setImageBitmap(out);
                    }
                });

            }
        }).start();
    }

}
