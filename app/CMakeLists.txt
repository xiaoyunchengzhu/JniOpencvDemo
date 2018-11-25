# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(path_to_opencv /home/zhangshiyu/Downloads/OpenCV-android-sdk)


add_library(
             base_opencv
             SHARED
             src/main/cpp/source/opencv_jni_util.cpp
             src/main/cpp/source/smoothing.cpp
             src/main/cpp/source/basefunction.cpp
             src/main/cpp/source/eroding_and_dilating.cpp
              )
include_directories(
             src/main/cpp/header
             )
include_directories(
             ${path_to_opencv}/sdk/native/jni/include
             )

add_library(
            lib_opencv
            SHARED
            IMPORTED
           )

set_target_properties(lib_opencv
                     PROPERTIES
                     IMPORTED_LOCATION
                     ${path_to_opencv}/sdk/native/libs/${ANDROID_ABI}/libopencv_java3.so
                     #src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so
                     )
find_library(
              log-lib
              log )
#find_library(
#              bitmap-lib
#              bitmap )

target_link_libraries(
                       base_opencv
                       ${log-lib}
                       jnigraphics
                       lib_opencv
                        )