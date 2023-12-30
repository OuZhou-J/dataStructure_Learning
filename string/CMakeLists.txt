
set(libname "stringFunc")

#添加宏定义，DEBUG,是否打印getNext值
# add_definitions(-DDEBUG)

#添加宏定义，NEXTPRO,用于区分不同getNext函数
# add_definitions(-DNEXTPRO)

#添加动态库
add_library(${libname} SHARED relationFunc.cpp)

#添加头文件路径
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})