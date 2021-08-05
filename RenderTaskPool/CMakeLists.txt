cmake_minimum_required (VERSION 3.8)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} RenderTaskPoolLibSrc)

add_library (RenderTaskPool STATIC ${RenderTaskPoolLibSrc} )

target_link_libraries(RenderTaskPool "ImGui")

target_include_directories(RenderTaskPool PUBLIC ${PROJECT_SOURCE_DIR})

