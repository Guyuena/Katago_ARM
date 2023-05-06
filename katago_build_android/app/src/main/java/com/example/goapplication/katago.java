package com.example.goapplication;


import android.util.Log;

import java.util.concurrent.TimeUnit;

public class katago {


//    // Used to load the 'native-lib' library on application startup.
//    static {
//        System.loadLibrary("native-lib1209");
//    }
////    public static native int main("123");
//    public static native int stateCondition();
////    public static native int chessCalibration1(byte[] pixels, int w, int h,int j,String path);

//    final String TAG = "Katago_test";
//    public boolean isLoad = false;
//    private stdoutLister sListener = null;
//    private  boolean isThinking = false;
//    static {
//
//        System.loadLibrary("katago6");
//    }
//
//    public katago(final String filename){
//        new Thread(new Runnable() {
//            @Override
//            public void run() {
//                // TODO Auto-generated method stub
//                StartEngine(filename);
////                processbuildertest();
//                isLoad = true;
//            }
//        }).start();
//    }
//
//
//
//    public void startMonitor(){
//        if(sListener !=null){
//            sListener.interrupt();
//        }
//        sListener = new stdoutLister();
//        sListener.start();
//    }
//
//    public void sendGtp(String cmd){
//        if(!isLoad)
//            return;
//        SendGtp_cmd(cmd);
//    }
//    public void clearboard() {
//        sendGtp("clear_board");
//    }
//    public void genMove(String color) {
//        String cmd = "genmove " + color;
//        while(isThinking) {
//            try {
//                TimeUnit.MILLISECONDS.sleep(4);
//            }
//            catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//        };
//        isThinking = true;
//        sendGtp(cmd);
//        isThinking = false;
//    }
//
//
//
//    private class stdoutLister extends Thread {
//        @Override
//        public void run() {
//            super.run();
//            while(!isInterrupted()){
//                try {
//                    String sout = getStdoutFromJNI();
//                    if(sout.isEmpty()) {
//                        Thread.sleep(10);
////                        System.out.println("命令终端返回为空");
//                        continue;
//                    }
//
////                    System.out.println("命令终端返回数据类型" + sout);
////                    System.out.println("命令终端返回" + sout);
//                    Log.i(TAG,sout);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                    Log.i(TAG,Thread.currentThread().getName()+"InterruptedException");
//                    break;
//                }
//            }
//        }
    }
//    public native String stringFromJNI();
//    private native String getStdoutFromJNI();
//    private native int StartEngine(String weight);
//    private native int SendGtp_cmd(String cmd);
//}
