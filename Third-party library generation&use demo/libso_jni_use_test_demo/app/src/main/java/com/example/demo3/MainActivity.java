package com.example.demo3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.demo3.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'demo3' library on application startup.
    static {
        System.loadLibrary("demo3");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
//        tv.setText(stringFromJNI());
//        tv.setText(String.valueOf(Jniaddtest(10000,333333)));
                tv.setText(test_C_jni());
    }

    /**
     * A native method that is implemented by the 'demo3' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native int Jniaddtest(int a,int b);
    public native String test_C_jni();
}