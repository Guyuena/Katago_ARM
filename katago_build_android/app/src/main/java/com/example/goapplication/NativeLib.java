package com.example.goapplication;

public class NativeLib {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib1209");
        System.loadLibrary("katago");
    }
        public static native int main();
//    public static native int reinition();
//    public static native int stateCondition();
//    public static native int chessCalibration1(byte[] pixels, int w, int h,int j,String path);



}

