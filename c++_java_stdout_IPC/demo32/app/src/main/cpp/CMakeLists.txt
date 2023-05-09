# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("demo3")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.


# 添加一个新的库，由新的源码生成
add_library( # Sets the name of the library.
        demo3
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        native-lib.cpp
        cmdline.cpp
        katago.cpp
        time_thread.cpp
        )

# cmake调试信息
message("CMAKE_ANDROID_ARCH_ABI: ",${CMAKE_ANDROID_ARCH_ABI})
# 声明一个变量 libs_DIR 并且赋值
# ${CMAKE_SOURCES_DIR} 是 cmake 自带的参数，可以直接使用
set(libs_DIR ${CMAKE_SOURCE_DIR}/../jni/${CMAKE_ANDROID_ARCH_ABI})
message("libs_DIR: ",${libs_DIR})

#链接第三方库的头文件
#target_include_directories()


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





# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.



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



#正常情况下，一个apk启动后只会运行在一个进程中，其进程名为AndroidManifest.xml文件中指定的应用包名，
#所有的基本组件都会在这个进程中运行。但是如果需要将某些组件（如Service、Activity等）运行在单独的进程中，
#就需要用到android:process属性了。我们可以为android的基础组件指定process属性来指定它们运行在指定进程中

