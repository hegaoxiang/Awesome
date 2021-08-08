cmake_minimum_required (VERSION 3.8)

#target_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
project("template")

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} RenderTaskPoolLibSrc)

add_library (template SHARED ${RenderTaskPoolLibSrc})

target_link_libraries(template "RenderTaskPool" "ImGui")

target_link_directories(template PRIVATE D:/repo/Awesome/Awesome/out/build/x64-Debug/RenderTaskPool D:/repo/Awesome/Awesome/out/build/x64-Debug/ImGui)
target_include_directories(template PRIVATE D:/repo/Awesome/Awesome )

#target_include_directories(test2 PRIVATE ${PROJECT_SOURCE_DIR})

