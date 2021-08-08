cmake_minimum_required (VERSION 3.8)

#target_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} RenderTaskPoolLibSrc)

add_library (template SHARED ${RenderTaskPoolLibSrc})

target_link_libraries(template "RenderTaskPool" "ImGui")

target_include_directories(template PRIVATE ${PROJECT_SOURCE_DIR})

