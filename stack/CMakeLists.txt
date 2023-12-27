
set(libname useStack)
add_library(${libname} SHARED ${libname}.cpp)
target_include_directories(${libname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})