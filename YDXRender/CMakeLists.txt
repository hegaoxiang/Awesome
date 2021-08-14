cmake_minimum_required (VERSION 3.8)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} YDXRenderLibSrc)


add_library (YDXRender STATIC ${YDXRenderLibSrc})

target_link_libraries(YDXRender PUBLIC "ImGui"  d3d11.lib d3dcompiler.lib dxgi.lib)

target_include_directories(YDXRender PUBLIC ${PROJECT_SOURCE_DIR})

