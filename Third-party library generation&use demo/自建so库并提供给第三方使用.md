# 生成库



## 第一步：

Android studio 新建带有c++支持的工程

<img src="C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506172714934.png" alt="image-20230506172714934" style="zoom:50%;" />

## 第二步：

添加需要编译成库的c++源码

![image-20230506172844069](C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506172844069.png)

native-lib.cpp是工程自己添加的，test.cpp是自己添加的源码



**test.cpp**

```
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

```



**test.h**

```
//
// Created by jc on 2023/5/4.
//

#ifndef _TEST_H
#define _TEST_H

#include <string>


int Jniadd(int x, int y);

int jni_test_fun1(int a,int b ,int  c);

std::string jni_test_fun2();


#endif //KATAGO20230504_TEST_H

```



## 第三步：

处理cmakelists.txt编译规则

```
project("katago20230504")

# 把需要编译的cpp源码放进来
set( SOURCES
        native-lib.cpp
        test.cpp  
        )
add_library( # Sets the name of the library.
        katago20230504
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        ${SOURCES})

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)


target_link_libraries( # Specifies the target library.
        katago20230504
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})
```



## 第四步：

编译运行

<img src="C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506173418847.png" alt="image-20230506173418847" style="zoom: 50%;" />

<img src="C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506173516238.png" alt="image-20230506173516238" style="zoom:50%;" />



可以看到自己设计的c++函数能够成功调用





并生成如下架构的共享库文件



<img src="C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506173314394.png" alt="image-20230506173314394" style="zoom:50%;" />









# 调用库

## 第一步：

新建支持c++的Android工程

<img src="C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506173748650.png" alt="image-20230506173748650" style="zoom:50%;" />



## 第二步：

添加动态库

在main目录下新加一个jni目录

<img src="C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506173913651.png" alt="image-20230506173913651" style="zoom:50%;" />



把在生成库的文件放进来

![image-20230506173957041](C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506173957041.png)

![image-20230506174024347](C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506174024347.png)



## 第三步：

cmakelists.txt中添加库

把需要的库链接进来

```

cmake_minimum_required(VERSION 3.18.1)

project("demo3")
# 添加一个新的库，由新的源码生成
add_library( # Sets the name of the library.
        demo3
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        native-lib.cpp)

# cmake调试信息
message("CMAKE_ANDROID_ARCH_ABI: ",${CMAKE_ANDROID_ARCH_ABI})
# 声明一个变量 libs_DIR 并且赋值
# ${CMAKE_SOURCES_DIR} 是 cmake 自带的参数，可以直接使用
set(libs_DIR ${CMAKE_SOURCE_DIR}/../jni/${CMAKE_ANDROID_ARCH_ABI})
message("libs_DIR: ",${libs_DIR})

# 添加一个库，在这里可以理解为声明了一个变量，来承载需要引入的库
add_library(
#        libkatago20230504  # 表示的是模块名称，可以自己任意取，但要和下面的set_target_properties名字一致
        you_need_import_libso  # 表示的是模块名称，可以自己任意取，但要和下面的set_target_properties名字一致
        SHARED # 这个是固定的，基本上表示共享库
        IMPORTED) # IMPORTED 表示当前是导入的

# set_target_properties 这个库设置so文件链接的位置
set_target_properties(
#        libkatago20230504
        you_need_import_libso
        PROPERTIES IMPORTED_LOCATION # 表示当前库是导入的方式
#        ${CMAKE_SOURCE_DIR}/../jni/${CMAKE_ANDROID_ARCH_ABI}/libkatago20230504.so) # so动态库的具体路径
#        或者使用上面提前声明的路径变量 libs_DIR
        ${libs_DIR}/libkatago20230504.so)# so动态库的具体路径

# 如果第三方库有头文件的，为了在编码的时候可以有提示，使用下面的指令进行指定
# 这里是指定头文件那些的目录，这样指定后，编译器会扫描这个目录，编码的时候就可以提示到这里的方法了，不加这个也不会报错
#include_directories(${CMAKE_SOURCE_DIR}/include)  # 注意自己的include路径


find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)


# 链接所有的库.
target_link_libraries( # Specifies the target library.
        demo3  # 这个是想要生成的目标库
        # ${libkatago20230504}  # 需要链接进来的库
#   ${libkatago20230504} 这么写会报错，所以网上讲的不一定对     C/C++: clang++: error: linker command failed with exit code 1 (use -v to see invocation)
#        libkatago20230504
        you_need_import_libso
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}# 需要链接进来的库
        )

#Device supports x86,armeabi-v7a,armeabi,but APK only supports arm-v8a
# 因为在app下的build.gradlez中的 abiFilters只配置了arm-v8a,而Android studio的虚拟机目前还不单独支持arm64-v8a
# 把arm32位也加上就好了
#       ndk {
#           abiFilters  "arm64-v8a","armeabi-v7a"
#       }
```



## 第四步：

添加库的函数的头文件，把需要用到的so里面的函数的头文件进行声明

![image-20230506174427776](C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506174427776.png)

```
//
// Created by jc on 2023/5/4.
//

#ifndef _TEST_H
#define _TEST_H

#include <string>


int Jniadd(int x, int y);

int jni_test_fun1(int a,int b ,int  c);

std::string jni_test_fun2();


#endif //KATAGO20230504_TEST_H
```



## 第五步：

本地调用测试

**注意在要使用so函数的地方导入函数头文件**

![image-20230506174813379](C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506174813379.png)

<img src="C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506174610886.png" alt="image-20230506174610886" style="zoom:50%;" />

![image-20230506174725989](C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506174725989.png)

```
#include <jni.h>
#include <string>
#include "include/test.h"
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_demo3_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_demo3_MainActivity_Jniaddtest(JNIEnv *env, jobject thiz, jint a, jint b) {
    // TODO: implement Jniaddtest()
    int result = Jniadd(a,b);

    return result;
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_demo3_MainActivity_test_1C_1jni(JNIEnv *env, jobject thiz) {
    // TODO: implement test_C_jni()
    std::string jni_result = jni_test_fun2();
    return env->NewStringUTF(jni_result.c_str());
}
```





**第三方库调用成功**

![image-20230506174953980](C:\Users\jc\AppData\Roaming\Typora\typora-user-images\image-20230506174953980.png)





