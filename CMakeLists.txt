#CMake 最低版本号要求 
cmake_minimum_required (VERSION 2.8)

#项目名称
project (freertos_test)

#源码文件夹
aux_source_directory (src SRCS_DIR)

#include path
include_directories (inc)
	
#指定生成目标
add_executable (freertos_test ${SRCS_DIR})

#编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os -Wall -ggdb -pthread")

