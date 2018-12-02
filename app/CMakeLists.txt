# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
set(libs_DIR ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})

set(libs_DIR_header_opencv src/main/cpp/opencv/include)


file(GLOB native_srcs "src/main/cpp/source/*.cpp")
file(GLOB native_header "src/main/cpp/header/*.h")

add_library(
        base_opencv
        SHARED
        ${native_srcs}
        ${native_header}
)


add_library(
        lib_opencv
        SHARED
        IMPORTED
)

set_target_properties(lib_opencv
        PROPERTIES
        IMPORTED_LOCATION
        ${libs_DIR}/libopencv_java3.so
        )

target_include_directories(base_opencv PUBLIC
        ${libs_DIR_header_opencv}
        )
find_library(
        log-lib
        log)

target_link_libraries(
        base_opencv
        ${log-lib}
        jnigraphics
        lib_opencv
)