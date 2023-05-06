package com.example.katago20230504;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.katago20230504.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'katago20230504' library on application startup.
    static {
        System.loadLibrary("katago20230504");
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
        tv.setText(String.valueOf(Jniadd(456456,78)));
//        tv.setText(test_C_jni());
    }



    /**
     * A native method that is implemented by the 'katago20230504' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
//    通过快捷键（alt + shift + enter）自动在native-lib.cpp中生成接口，接口符合jni命名规则。
    public native int Jniadd(int a, int b);
    public native String test_C_jni();

}