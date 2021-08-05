cmake_minimum_required (VERSION 3.8)

#target_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} RenderTaskPoolLibSrc)

add_library (test2 SHARED ${RenderTaskPoolLibSrc})

target_link_libraries(test2 "RenderTaskPool" "ImGui")

target_include_directories(test2 PRIVATE ${PROJECT_SOURCE_DIR})

