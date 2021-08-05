cmake_minimum_required (VERSION 3.8)

#target_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} RenderTaskPoolLibSrc)

add_library (RenderTaskPool STATIC ${RenderTaskPoolLibSrc} )

target_link_libraries(RenderTaskPool )

target_include_directories(RenderTaskPool PRIVATE ${PROJECT_SOURCE_DIR})

