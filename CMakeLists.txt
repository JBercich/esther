# CMakeLists
# ---------- 

# The application build process uses CMakeLists for constructing a build `makefile` and
# simplify abstracting between application files, static libraries and packages used in
# the application. A monolithic-styled project structure is used where all source file
# subdirectories contain a manually written `CMakeLists.txt` file at the recommendation
# of the developer.

# Builds for the project should be performed in the `/build` subdirectory to prevent 
# any build files within the application source. Application bundles will be created in
# this subdirectory with any other bundling procedures. During builds, a configuration
# file for static "absolute" data is created in the top-level `/include` subdirectory.

# -------------------------------------------------------------------------------------- 
# Project definition
# -------------------------------------------------------------------------------------- 

# This project will use a modern `cmake` version. The majority of any project based
# logic for building out the project source will use the name given to the project to
# make any future changes much easier by only changing this title. The project version
# may fall out of sync in the future when using some form of CI distribution building
# tool since this file should remain fairly unchanged.

cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME        "Esther")
set(PROJECT_NAME_ENGINE "Engine")

project(${PROJECT_NAME} LANGUAGES CXX VERSION 0.1.0)

# Using the latest CMP0076 policy allows the addition of sources for the target exec.
# using target_sources within subdirectories after the definition of the executable.
# Using the latest CMP0079 policy allows the addition of the simultaneously built 
# engine static library to be added from a project subdirectory where it is defined at
# its respective top-level `/src/Engine` subdirectory.

cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)

# -------------------------------------------------------------------------------------- 
# Build configuration variables
# -------------------------------------------------------------------------------------- 

# Latest CXX versions are used in the application and is used explicitly so this is an
# enforced requirement. This should be available on all expected cross-platforms.

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Explicit definition of GCC and MSVC CXX compiler identifiers are defined for future
# logic to add compiler specific flags for makefiles when adding any release-specific
# optimisation flags when performing builds.

set(GCC_CXX_COMPILER "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_CXX_COMPILER "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# Build types and conforming to these within the logic of this build pipeline is defined
# below. There will be four options to choose from that must be chosen or this will be
# defaulted to a debug release.
#   Debug: Basic build with debug information.
#   Release: Basic release without debug information (fast).
#   MinSizeRel: Basic release without debug information (small).
#   RelWithDebInfo: Basic release with debug information.

set(CMAKE_BUILD_TYPE_DEBUG "Debug")
set(CMAKE_BUILD_TYPE_RELEASE "Release")
set(CMAKE_BUILD_TYPE_MINSIZEREL "MinSizeRel")
set(CMAKE_BUILD_TYPE_RELWITHDEBINFO "RelWithDebInfo")
set(CMAKE_BUILD_TYPES_LIST 
    ${CMAKE_BUILD_TYPE_DEBUG}, 
    ${CMAKE_BUILD_TYPE_RELEASE}, 
    ${CMAKE_BUILD_TYPE_MINSIZEREL}, 
    ${CMAKE_BUILD_TYPE_RELWITHDEBINFO})

list(FIND CMAKE_BUILD_TYPES_LIST CMAKE_BUILD_TYPE TEMP_INDEX)
if(${TEMP_INDEX} GREATER -1)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# -------------------------------------------------------------------------------------- 
# Testing framework
# -------------------------------------------------------------------------------------- 

# Generic CTest framework implementation is defined here. Although I have no experience
# with CTest, it is my future goal to create a basic unit-testing suite which is very 
# important considering how quickly this application is gaining breadth.

include(CTest)
enable_testing()

# -------------------------------------------------------------------------------------- 
# Package management
# -------------------------------------------------------------------------------------- 

# Packages should be installed manually within the build environment and using the
# expected system locations for the `find_package` routines to work effectively. In the
# future, path hints will be given if necessary, however this is a very low-level 
# application with very few dependencies so this should not be required since only very
# popular and well-maintained packages are used.

find_package(SDL2         2.26.5  REQUIRED)
find_package(SDL2_image   2.6.2   REQUIRED)
find_package(SDL2_mixer   2.6.2   REQUIRED)
find_package(SDL2_ttf     2.20.1  REQUIRED)
find_package(spdlog       1.11.0  REQUIRED)

# -------------------------------------------------------------------------------------- 
# Executable target
# -------------------------------------------------------------------------------------- 

# A single application executable is built. App bundling is performed later on, however,
# The inclusion of different packages such as `spdlog` is required here as a linked and
# included library for use. Other packages such as `SDL2` will be used through a wrapepr
# in the engine static library.

add_executable(${PROJECT_NAME} src/Main.cpp)

target_include_directories(
    ${PROJECT_NAME} 
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${SPDLOG_INCLUDE_DIR} 
)

target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE 
        spdlog::spdlog
)

# All remaining CMakeLists logic remains in the `/src` subdirectory which will contain
# further documentation on the abstraction of the engine and game targets and how they
# are built up recursively.

add_subdirectory(src)

# -------------------------------------------------------------------------------------- 
# Compilation options
# -------------------------------------------------------------------------------------- 

# Changes to the compilation options are implemented below. This will be expanded in the
# future to have additional compilation flags for each pre-processor dependent on OS of
# the build and the build type to optimise for different build requirements.

target_compile_options(
    ${PROJECT_NAME} 
    INTERFACE
        "$<${GCC_CXX_COMPILER}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
        "$<${MSVC_CXX_COMPILER}:$<BUILD_INTERFACE:-W3>>"
)

# -------------------------------------------------------------------------------------- 
# Exporing configuration data
# -------------------------------------------------------------------------------------- 

# A build configuration header file is generated with important information from the
# build process to be available within the application itself such as package versions,
# debugging flags, etc. The file is located in the `/include` subdirectory for both the
# engine and game source files to use this information. In the future, the engine should
# be initialised without referencing this file and take any required data from some
# initialisation argument set.

configure_file(
    ${PROJECT_SOURCE_DIR}/include/BuildConfig.hpp.in 
    ${PROJECT_SOURCE_DIR}/include/BuildConfig.hpp
)

# -------------------------------------------------------------------------------------- 
# Application bundling
# -------------------------------------------------------------------------------------- 

# CPack bundling is shown below, however, for cross-platform builds there may be other
# tools required such as creating a MacOS app bundle or a win32 QT application. The use
# of CPack will likely change in the future.

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
