package com.example.goapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.goapplication.databinding.ActivityMainBinding;
import com.example.goapplication.test_katago;
import com.example.goapplication.NativeLib;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'katago6' library on application startup.
    static {
        System.loadLibrary("katago6");
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

//        int  finshed = NativeLib.stateCondition();  //判断
//        System.out.println("finshed"+ finshed);
//         int a = test_katago.test_katago();
//        Log.i("sssss","a:"+ a );
//        NativeLib.main();
        Process  precess  = null ;

        List<String> params = new ArrayList<String>();
        params.add("pwd");
        params.add("/libkatago.so");
        params.add("analysis");


        ProcessBuilder processBuilder = new ProcessBuilder(params);
        Map<String, String> env = processBuilder.environment();
        processBuilder.redirectErrorStream(true);
        try {
            Process process = processBuilder.start();
            BufferedReader br = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println("line111111111111111"+line);
            }
            int exitCode = process.waitFor();
            System.out.println("--->>>>>  exitCode <<<<<<<---- = "+exitCode);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }


    }

    /**
     * A native method that is implemented by the 'katago6' native library,
     * which is packaged with this application.
     */
//    public native String stringFromJNI();
}