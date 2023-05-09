//
// Created by jc on 2023/5/8.
//

#include <string>
#include <iostream>
#include <unistd.h>
#include "include/katago.h"

static int pfd[2];
static FILE *stdoutFile = nullptr;
static bool isRedirect = false;



// 通过管道pipe来不断获取由 c++源码程序向终端界面输出的结果信息
std::string getStdout() {
    if(!isRedirect){ // 是否已经重定向
        setvbuf(stdout, 0, _IONBF, 0); // 终端标准输出
        setvbuf(stderr, 0, _IONBF, 0); // 终端错误输出
        pipe(pfd); // pipe函数可用于创建一个管道，以实现进程间的通信
        dup2(pfd[1], STDOUT_FILENO);  // 把本该在 STDOUT_FILENO中的内容重定向到pdf[1]中
        dup2(pfd[1], STDERR_FILENO);  // 把本该在 STDERR_FILENO 中的内容重定向到pdf[1]中
        stdoutFile = fdopen(pfd[0], "r"); // 从管道里面读输出
        close(pfd[1]);
        isRedirect = true;  // 标志位，完成数据流重定向
    }
////  完成数据流重定向之后就是一直读取信息：
    char buf[512];
    fgets(buf, sizeof(buf), stdoutFile);
////    char[] 转string  直接赋值即可
    std::string hello = buf;
//    char buf2[100]= {"20230507xjc-----****"};
//    std::string hello2 = buf2;

    return hello;  // 返回读到字符串结果
//    将获得的终端信息转为字符串，并返回给Java的jni
}

std::string testOut(){

    std::string hello2 = "20230507xjc";

    return hello2;  // 返回读到字符串结果

}