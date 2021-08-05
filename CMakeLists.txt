# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("Awesome")

#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Lib)


set(CMAKE_CXX_STANDARD 17)
# 包含子项目。
add_subdirectory ("Awesome")

add_subdirectory("RenderTaskPool")

add_subdirectory("ImGui")

add_subdirectory("test1")

add_subdirectory("test2")
