cmake_minimum_required (VERSION 3.0)

project (OpenCL_HelloWorld)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries/${CMAKE_SYSTEM_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries/${CMAKE_SYSTEM_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries/${CMAKE_SYSTEM_NAME})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

if (APPLE)
	find_library(OPENCL_LIBRARY OpenCL)
elseif (UNIX)
	set(CMAKE_C_FLAGS "-std=c99")
	include_directories("/opt/AMDAPPSDK-2.9-1/include")
	link_directories("/opt/AMDAPPSDK-2.9-1/lib/x86_64")
	set (OPENCL_LIBRARY OpenCL)
elseif (WIN32)
	include_directories("C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v7.0\\include")
	link_directories("C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v7.0\\lib\\x64")
	set (OPENCL_LIBRARY OpenCL)
endif(APPLE)

add_executable(HelloWorld Source/main.c Source/err_code.h)
set_target_properties(HelloWorld PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(HelloWorld ${OPENCL_LIBRARY})

include_directories (Source)
