# ======================================================================================
# CMake overview
# ======================================================================================
# CMake is used as the main build tool for this repository. This will use a monolithic-
# styled build with CMakeLists.txt specified in each directory inline with the developer 
# recommendations. 
# ======================================================================================

cmake_minimum_required(VERSION 3.0.0)
project(Esther LANGUAGES CXX VERSION 0.1.0)

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GCC_CXX_COMPILER "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_CXX_COMPILER "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

include(CTest)
enable_testing()

# Package management is manually done for each system by installing required packages
# in the `external` subdirectory and the operating system of choice. This can also be
# stored elsewhere but provides a single entrypoint HINT for the search pattern.

find_package(SDL2         2.26.5  REQUIRED HINTS ${CMAKE_SOURCE_DIR}/external)
find_package(SDL2_image   2.6.2   REQUIRED HINTS ${CMAKE_SOURCE_DIR}/external)
find_package(SDL2_mixer   2.6.2   REQUIRED HINTS ${CMAKE_SOURCE_DIR}/external)
find_package(SDL2_ttf     2.20.1  REQUIRED HINTS ${CMAKE_SOURCE_DIR}/external)
find_package(spdlog       1.11.0  REQUIRED HINTS ${CMAKE_SOURCE_DIR}/external)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(
    Esther 
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${SPDLOG_INCLUDE_DIR} 
)

target_link_libraries(
    Esther 
    PRIVATE 
        spdlog::spdlog
)

add_subdirectory(src)

target_compile_options(
    ${PROJECT_NAME} 
    INTERFACE
        "$<${GCC_CXX_COMPILER}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${MSVC_CXX_COMPILER}:$<BUILD_INTERFACE:-W3>>"
)

configure_file(
    ${PROJECT_SOURCE_DIR}/include/Build/BuildConfig.hpp.in 
    ${PROJECT_SOURCE_DIR}/include/Build/BuildConfig.hpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
