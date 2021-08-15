cmake_minimum_required (VERSION 3.8)


add_library(Tinygltf INTERFACE)
target_include_directories(Tinygltf INTERFACE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)



