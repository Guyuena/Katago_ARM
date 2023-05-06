//
// Created by jc on 2023/5/4.
//
#include "test.h"

int Jniadd(int x, int y) {
    return x + y;

}

int jni_test_fun1(int a,int b,int c){

    int r = a+b;
    int r2= r*c;
    return  r2;

}
std::string jni_test_fun2(){
    return "2023-05-06-test-java-jni";

}
