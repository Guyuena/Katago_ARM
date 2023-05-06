# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("katago6")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SRC_CPP)
#message(WARNING "SRC_CPP is" ${SRC_CPP})
set(CMAKE_CXX_STANDARD 14)
include_directories(katago/external)  # 包含external文件目录
include_directories(katago/external/tclap-1.2.2/include/tclap) # 包含external/tclap-1.2.2/include目录  里面有需要的头文件
include_directories(katago/external/filesystem-1.5.8/include)
#set(NEURALNET_BACKEND_SOURCES   ../katago/neuralnet/eigenbackend.cpp )
set(EIGEN3_INCLUDE_DIRS katago/Eigen3/include/eigen3)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})

#find_package(eigen3 REQUIRED)
#include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})
#message(WARNING "Found Eigen3 at ${EIGEN3_INCLUDE_DIRS}")

#include_directories(libzip)

#add_subdirectory(libzip)


#add_library (boost_program_options SHARED IMPORTED)
#set_target_properties( boost_program_options PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libboost_program_options.so
#        )
#add_library (boost_filesystem SHARED IMPORTED)
#set_target_properties( boost_filesystem PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libboost_filesystem.so
#        )

#
#file(GLOB KATAGO_SRC ${CMAKE_SOURCE_DIR}/katago/core/*.cpp ${CMAKE_SOURCE_DIR}/katago/core/*.h
#        ${CMAKE_SOURCE_DIR}/katago/game/*.cpp ${CMAKE_SOURCE_DIR}/katago/game/*.h
#
#        )



# 这种方式就是把目录下所有的源码文件都包含进来
AUX_SOURCE_DIRECTORY(katago/book book_CPP)
AUX_SOURCE_DIRECTORY(katago/command command_CPP)
AUX_SOURCE_DIRECTORY(katago/core core_CPP)
AUX_SOURCE_DIRECTORY(katago/game game_CPP)
AUX_SOURCE_DIRECTORY(katago/dataio dataio_CPP)
AUX_SOURCE_DIRECTORY(katago/program program_CPP)
AUX_SOURCE_DIRECTORY(katago/search search_CPP)
AUX_SOURCE_DIRECTORY(katago/tests tests_CPP)

set(SOURCE_BOOK
        katago/book/book.cpp
        katago/book/bookcssjs.cpp
        )
set(SOURCE_NEURALNET
        katago/neuralnet/eigenbackend.cpp
        katago/neuralnet/nninputs.cpp
        katago/neuralnet/modelversion.cpp
        katago/neuralnet/nneval.cpp
        katago/neuralnet/desc.cpp
        )

set(SOURCE_CORE
        katago/core/global.cpp
        katago/core/base64.cpp
        katago/core/bsearch.cpp
        katago/core/config_parser.cpp
        katago/core/datetime.cpp
        katago/core/elo.cpp
        katago/core/fancymath.cpp
        katago/core/fileutils.cpp
        katago/core/hash.cpp
        katago/core/logger.cpp
        katago/core/makedir.cpp
        katago/core/md5.cpp
        katago/core/multithread.cpp
        katago/core/rand.cpp
        katago/core/rand_helpers.cpp
        katago/core/sha2.cpp
        katago/core/test.cpp
        katago/core/threadsafecounter.cpp
        katago/core/threadsafequeue.cpp
        katago/core/timer.cpp
        katago/core/mainargs.cpp

        )
set(SOURCE_COMMAND
        katago/command/commandline.cpp
        katago/command/analysis.cpp
        katago/command/benchmark.cpp
        katago/command/contribute.cpp
        katago/command/evalsgf.cpp
        katago/command/gatekeeper.cpp
        katago/command/gtp.cpp
        katago/command/match.cpp
        katago/command/matchauto.cpp
        katago/command/misc.cpp
        katago/command/runtests.cpp
        katago/command/sandbox.cpp
        katago/command/selfplay.cpp
        katago/command/tune.cpp
        )

set(SOURCE_GAME
        katago/game/board.cpp
        katago/game/rules.cpp
        katago/game/boardhistory.cpp
   
   
        )

set(SOURCE_DATAIO
        katago/dataio/sgf.cpp
        katago/dataio/numpywrite.cpp
        katago/dataio/trainingwrite.cpp
        katago/dataio/loadmodel.cpp
        katago/dataio/homedata.cpp
        katago/dataio/files.cpp
        )

set(SOURCE_PROGRAM
        katago/program/gtpconfig.cpp
        katago/program/setup.cpp
        katago/program/playutils.cpp
        katago/program/playsettings.cpp
        katago/program/play.cpp
        katago/program/selfplaymanager.cpp
        )
set(SOURCE_SEARCH
        katago/search/timecontrols.cpp
        katago/search/searchparams.cpp
        katago/search/mutexpool.cpp
        katago/search/search.cpp
        katago/search/searchresults.cpp
        katago/search/asyncbot.cpp
        katago/search/distributiontable.cpp
        katago/search/localpattern.cpp
        katago/search/subtreevaluebiastable.cpp
        katago/search/patternbonustable.cpp
        katago/search/analysisdata.cpp
        )

set(SOURCE_TESTS
        katago/tests/testboardarea.cpp
        katago/tests/testboardbasic.cpp
        katago/tests/testcommon.cpp
        katago/tests/testnnevalcanary.cpp
        katago/tests/testrules.cpp
        katago/tests/testscore.cpp
        katago/tests/testsgf.cpp
        katago/tests/testsymmetries.cpp
        katago/tests/testnninputs.cpp
        katago/tests/testownership.cpp
        katago/tests/testsearchcommon.cpp
        katago/tests/testsearchnonn.cpp
        katago/tests/testsearch.cpp
        katago/tests/testsearchv3.cpp
        katago/tests/testsearchv8.cpp
        katago/tests/testsearchmisc.cpp
        katago/tests/testtime.cpp
        katago/tests/testtrainingwrite.cpp
        katago/tests/testnn.cpp
        katago/tests/tinymodel.cpp
        katago/tests/tinymodeldata.cpp   )

   







# 打印信息来查看是否获取到源码  Sync Now时log信息查看
message( WARNING "book_CPP_CPP: " ${book_CPP})
message( WARNING "command_CPP_CPP: " ${SOURCE_COMMAND})

message( WARNING "SOURCE_CORE: " ${SOURCE_CORE})
message( WARNING "game_CPP_CPP: " ${SOURCE_GAME})
message( WARNING "dataio_CPP_CPP: " ${SOURCE_DATAIO})
message( WARNING "SOURCE_NEURALNET: " ${SOURCE_NEURALNET})
message( STATUS "program_CPP_CPP: " ${SOURCE_PROGRAM})
message( WARNING "search_CPP_CPP: " ${SOURCE_SEARCH})
message( WARNING "tests_CPP_CPP: " ${SOURCE_TESTS})


add_library( # Sets the name of the library.
        katago6

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp
        katago.cpp
        katago/main.cpp
        ${SOURCE_COMMAND}
        ${SOURCE_CORE}
        ${SOURCE_GAME}
        ${SOURCE_DATAIO}
        ${SOURCE_BOOK}
        ${SOURCE_PROGRAM}
        ${SOURCE_SEARCH}
        ${SOURCE_TESTS}
        ${SOURCE_NEURALNET}






        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.


target_compile_definitions(katago6 PRIVATE USE_EIGEN_BACKEND)
find_package(ZLIB)
include_directories(${ZLIB_INCLUDE_DIRS})
message( WARNING "ZLIB_INCLUDE_DIRS: " ${ZLIB_INCLUDE_DIRS})
target_link_libraries(katago6 ${ZLIB_LIBRARIES})

add_library(mzip SHARED IMPORTED)
set_target_properties( mzip  PROPERTIES IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/armeabi-v7a/libzip.so
        )





find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        katago6

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        z
#        jnigraphics
#        boost_filesystem
#        boost_program_options
        mzip
        )

#[[
android NDK编译工程出现以下错误：

undefined reference to 'inflate'

undefined reference to 'inflateEnd'
undefined reference to 'inflateInit_'
undefined reference to 'inflateReset'
原因：这些都是libz.so库中的函数，程序没有导入libz动态库

解决方法：在Android.mk中加入

LOCAL_LDLIBS += -lz



]]

