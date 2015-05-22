cmake_minimum_required (VERSION 3.1)

project (OpenCL_HelloWorld)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries/${CMAKE_SYSTEM_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries/${CMAKE_SYSTEM_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries/${CMAKE_SYSTEM_NAME})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

find_library(OPENCL_FRAMEWORK OpenCL)

add_executable(HelloWorld Source/main.c Source/err_code.h)
set_target_properties(HelloWorld PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(HelloWorld ${OPENCL_FRAMEWORK})

include_directories (Source)
