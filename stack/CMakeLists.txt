
set(libname useStack)

#添加库
add_library(${libname} SHARED ${libname}.cpp)

#添加头文件路径
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})