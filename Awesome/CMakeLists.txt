# CMakeList.txt: Awesome 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} AwesomeSrc)

# 将源代码添加到此项目的可执行文件。
add_executable (Awesome ${AwesomeSrc}  "Serialize.h" "ECManager.h" )

target_link_libraries(Awesome "RenderTaskPool")

target_include_directories(Awesome PRIVATE ${PROJECT_SOURCE_DIR})


# TODO: 如有需要，请添加测试并安装目标。
