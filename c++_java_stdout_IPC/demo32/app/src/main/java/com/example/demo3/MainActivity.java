package com.example.demo3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.EditText;
import android.widget.TextView;

import com.example.demo3.databinding.ActivityMainBinding;
import android.util.Log;
import android.view.View;
import java.util.Vector;
import com.example.demo3.katago;
public class MainActivity extends AppCompatActivity {

    final String TAG = "KataGo-TEST";

    // Used to load the 'demo3' library on application startup.
    static {
        System.loadLibrary("demo3");
    }
    private static final String[] data = new String[]{
            "小猪猪", "小狗狗", "小鸡鸡", "小猫猫", "小咪咪"
    };

    private ActivityMainBinding binding;
//    public void onStart(View v) {
//        // TODO Auto-generated method stub
//        Log.i(TAG, "onStart");
//        KataGo.startMonitor();
//    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
//        AutoCompleteTextView atv_content = (AutoCompleteTextView) findViewById(R.id.autoCompleteTextView);
//        ArrayAdapter<String> adapter = new ArrayAdapter<String>(MainActivity.this, android.R.layout.simple_dropdown_item_1line, data);
//        atv_content.setAdapter(adapter);

//        EditText et = findViewById(R.id.editTextTextPassword);
//        String cmd = et.getText().toString();
//        System.out.println("input cmd= "+cmd);



        tv.setText(stringFromJNI());
//        tv.setText(String.valueOf(Jniaddtest(10000,333333)));
//        time_thread();
//                tv.setText(test2023());
//                int agrc=2;
//                String[] argv = {"as"};
//        String res = test2023();
//        System.out.println("res= "+res);
        katago KataGo = new katago();
        Log.i(TAG, "onStart");
        KataGo.startMonitor();
//        Log.i(TAG, "onStart KataGo end");

    }






//    public void onSend(View v) {
//        // TODO Auto-generated method stub
//        Log.i(TAG, "onSend");
//        EditText et = findViewById(R.id.editTextTextPassword);
//        String cmd = et.getText().toString();
//
//        System.out.println("input cmd= "+cmd);
//    }



    /**
     * A native method that is implemented by the 'demo3' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native int Jniaddtest(int a,int b);

    public native String test_C_jni();
    public native String test2023();
//    public native void time_thread();

}