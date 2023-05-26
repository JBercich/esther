# ======================================================================================
# CMake overview
# ======================================================================================
# CMake is used as the main build tool for this repository. This will use a monolithic-
# styled build with CMakeLists.txt specified in each directory inline with the developer 
# recommendations. 
# ======================================================================================

cmake_minimum_required(VERSION 3.0.0)
project(Esther LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GCC_CXX_COMPILER "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_CXX_COMPILER "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

include(CTest)
enable_testing()


# Get external packages using FetchContent and storing them in

include(FetchContent)

# Set FetchContent options
set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/external)


FetchContent_Declare(
  SDL2
    GIT_REPOSITORY    https://github.com/libsdl-org/SDL.git
    GIT_TAG           release-2.26.5
    GIT_SHALLOW       TRUE
    GIT_PROGRESS      TRUE
)
FetchContent_MakeAvailable(SDL2)

include_directories(${SDL2_SOURCE_DIR}/include)


add_executable(${PROJECT_NAME} src/main.cpp)


target_link_libraries(
  Esther 
    SDL2::SDL2main 
    SDL2::SDL2-static
)




target_compile_options(
    ${PROJECT_NAME} 
    INTERFACE
        "$<${GCC_CXX_COMPILER}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${MSVC_CXX_COMPILER}:$<BUILD_INTERFACE:-W3>>"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

