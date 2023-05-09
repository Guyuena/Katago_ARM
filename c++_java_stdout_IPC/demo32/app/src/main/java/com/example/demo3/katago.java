package com.example.demo3;
import android.util.Log;

import java.util.concurrent.TimeUnit;



public class katago {


    final String TAG = "KATAGO.java-TEST";
    public  boolean isLoad = false;
    private stdoutListen sListener = null;


    public katago(){
        Log.i(TAG,Thread.currentThread().getName());
        new Thread(new Runnable() {
            @Override
            public void run() {
                // TODO Auto-generated method stub
                String[] argv = {"as","gf"};
//                int a = test_mian2023(2,argv);
                time_thread_katago(); // 启动一个c++测试程序，这个程序可以不断地向终端输出信息
                Log.i(TAG,"katago() 1 ");
                isLoad = true;
            }
        }).start();
    }



    public void startMonitor() {
        Log.i(TAG,"katago.java startMonitor() 1 ");
        if(sListener != null) {
            Log.i(TAG,"katago.java startMonitor() 2 ");
            sListener.interrupt();  // 判断当前线程是否存在interrupted标志，存在话就顺便清除此标志
        }
        sListener = new stdoutListen();  // c++终端标准输出信息的监听子线程
        sListener.start();
        Log.i(TAG,"katago.java startMonitor()  3 ");
    }



    private class stdoutListen extends Thread {

        @Override
        public void run() {
            super.run();
            Log.i(TAG,Thread.currentThread().getName()+"InterruptedException--1");
            System.out.println("线程中断状态" + Thread.currentThread().isInterrupted());
            while(!isInterrupted()){ // 判断当前线程是否存在interrupted标志
                Log.i(TAG,Thread.currentThread().getName()+"InterruptedException--2");
                try {
                    Log.i(TAG,Thread.currentThread().getName()+"InterruptedException--3");
                    String sout = getStdoutFromJNI(); // 通过jni接口获取c++的标准输出信息
                    Log.i(TAG,Thread.currentThread().getName()+"InterruptedException--4");


                    if(sout.isEmpty()) {
                        Log.i("终端结果","sout.isEmpty()");
                        Thread.sleep(10);
                        continue;
                    }
                    Log.i(TAG+"终端结果",sout);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                    Log.i(TAG,Thread.currentThread().getName()+"InterruptedException");
                    break;
                }
            }
        }

    }







    private native String getStdoutFromJNI();
    private native int test_mian2023(int i, String[] argv);
    public native void time_thread_katago();





}
