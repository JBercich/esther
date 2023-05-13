# ======================================================================================
# CMakeLists
# ======================================================================================
# This project has two targets from the src/ subdirectory being the Pong and SXSW execs.
# CMake is used to maintain the project and may not use perfect axiomatic CMake since
# this is such a large project with many subdirectories and separate components, but
# is explained throughout where necessary.
#
# This component is responsible for setting up the project. The expected build
# directory is build/ in order to create executables in the bin/ subdirectory. 
# ======================================================================================

cmake_minimum_required(VERSION 3.24.2)

project(Project LANGUAGES CXX)

# Set the CXX standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set filepaths for the project subdirectories
cmake_path(SET SOURCE_BINARY_DIR "${CMAKE_SOURCE_DIR}/bin")
cmake_path(SET SOURCE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
cmake_path(SET SOURCE_AUDIO_DIR "${CMAKE_SOURCE_DIR}/audio")
cmake_path(SET SOURCE_BUILD_DIR "${CMAKE_SOURCE_DIR}/build")
cmake_path(SET SOURCE_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/lib")
cmake_path(SET SOURCE_ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")

# Set configure file paths
cmake_path(SET SYSTEM_CONFIG_FILE "${SOURCE_BINARY_DIR}/BuildConfigSystem.hpp")
cmake_path(SET PROJECT_CONFIG_FILE "${SOURCE_BINARY_DIR}/BuildConfigProject.hpp")
cmake_path(SET PONG_CONFIG_FILE "${SOURCE_BINARY_DIR}/BuildConfigTargetPong.hpp")
cmake_path(SET SXSW_CONFIG_FILE "${SOURCE_BINARY_DIR}/BuildConfigTargetSXSW.hpp")
cmake_path(SET SYSTEM_CONFIG_FILE_IN "${SOURCE_BINARY_DIR}/BuildConfigSystem.hpp.in")
cmake_path(SET PROJECT_CONFIG_FILE_IN "${SOURCE_BINARY_DIR}/BuildConfigProject.hpp.in")
cmake_path(SET PONG_CONFIG_FILE_IN "${SOURCE_BINARY_DIR}/BuildConfigTargetPong.hpp.in")
cmake_path(SET SXSW_CONFIG_FILE_IN "${SOURCE_BINARY_DIR}/BuildConfigTargetSXSW.hpp.in")

# Read operating system information
message("-- Operating system information")
message("---- Tag \t -> ${CMAKE_SYSTEM}")
message("---- Name \t -> ${CMAKE_SYSTEM_NAME}")
message("---- Version \t -> ${CMAKE_SYSTEM_VERSION}")
message("---- Hostname \t -> ${CMAKE_HOST_SYSTEM_NAME}")
message("---- Processor \t -> ${CMAKE_SYSTEM_PROCESSOR}")

# Configure files that can be set from this CMakeLists
configure_file(${SYSTEM_CONFIG_FILE_IN} ${SYSTEM_CONFIG_FILE})

# Build the source directory executables
add_subdirectory(src)
