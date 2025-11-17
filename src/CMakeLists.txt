cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME        "Esther")

project(${PROJECT_NAME} LANGUAGES CXX VERSION 0.1.0)
cmake_policy(SET CMP0076 NEW)
cmake_policy(SET CMP0079 NEW)
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

include(CTest)
enable_testing()


add_executable(${PROJECT_NAME} main.cpp)

# find_package(SDL2         2.26.5  REQUIRED)
# find_package(SDL2_image   2.6.2   REQUIRED)
# find_package(SDL2_mixer   2.6.2   REQUIRED)
# find_package(SDL2_ttf     2.20.1  REQUIRED)
# find_package(spdlog       1.11.0  REQUIRED)

# # -------------------------------------------------------------------------------------- 
# # Executable target
# # -------------------------------------------------------------------------------------- 

# # A single application executable is built. App bundling is performed later on, however,
# # The inclusion of different packages such as `spdlog` is required here as a linked and
# # included library for use. Other packages such as `SDL2` will be used through a wrapepr
# # in the engine static library.

# add_executable(${PROJECT_NAME} src/Main.cpp)

# target_include_directories(
#     ${PROJECT_NAME} 
#     PRIVATE
#         ${CMAKE_SOURCE_DIR}/include
#         ${SPDLOG_INCLUDE_DIR} 
# )

# target_link_libraries(
#     ${PROJECT_NAME} 
#     PRIVATE 
#         spdlog::spdlog
# )

# # All remaining CMakeLists logic remains in the `/src` subdirectory which will contain
# # further documentation on the abstraction of the engine and game targets and how they
# # are built up recursively.

# add_subdirectory(src)

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

# # -------------------------------------------------------------------------------------- 
# # Exporing configuration data
# # -------------------------------------------------------------------------------------- 

# # A build configuration header file is generated with important information from the
# # build process to be available within the application itself such as package versions,
# # debugging flags, etc. The file is located in the `/include` subdirectory for both the
# # engine and game source files to use this information. In the future, the engine should
# # be initialised without referencing this file and take any required data from some
# # initialisation argument set.

# configure_file(
#     ${PROJECT_SOURCE_DIR}/include/BuildConfig.hpp.in 
#     ${PROJECT_SOURCE_DIR}/include/BuildConfig.hpp
# )

# -------------------------------------------------------------------------------------- 
# Application bundling
# -------------------------------------------------------------------------------------- 

# CPack bundling is shown below, however, for cross-platform builds there may be other
# tools required such as creating a MacOS app bundle or a win32 QT application. The use
# of CPack will likely change in the future.

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)





# -------

# The split between the engine static library and game is connected here where the
# engine is linked to the game target as a separate library. Each respective 
# subdirectory is then recursed on to complete the CMake build.

# add_subdirectory(${PROJECT_NAME_ENGINE})
# add_subdirectory(${PROJECT_NAME})

# target_include_directories(
#     ${PROJECT_NAME} 
#     PRIVATE 
#         ${PROJECT_NAME_ENGINE}
# )

# target_link_libraries(
#     ${PROJECT_NAME} 
#     PRIVATE 
#         ${PROJECT_NAME_ENGINE}
# )
