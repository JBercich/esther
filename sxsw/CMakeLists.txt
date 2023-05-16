# ======================================================================================
# CMakeLists
# ======================================================================================
# CMake is used as the main build tool for this repository. This will use a monolithic-
# styled build outline with CMakeLists files specified in each directory with files
# built individually inline with the creator recommendations. The target executable is
# built at runtime with additional tasks.
# ======================================================================================

# Setup the CMake project target for building the executable
cmake_minimum_required(VERSION 3.24.2)
project(SXSW LANGUAGES CXX VERSION 0.1.0)


# Set build options for the CMake project
option(RELEASE_EXECUTABLE_BUILD "Output executable is built as a release" OFF)
option(CMAKE_EXPORT_COMPILE_COMMANDS "Export the compilation commands for CMake" ON)
option(CMAKE_ENABLE_EXPORTS "Allows executable links to be shared with libraries" ON)

# Project subdirectory filepaths
cmake_path(SET BUILD_SOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/src")
cmake_path(SET BUILD_BINARY_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
cmake_path(SET BUILD_ASSETS_DIRECTORY "${CMAKE_SOURCE_DIR}/assets")

# Configuration filepaths
cmake_path(SET BUILD_CONFIG_FILE "${BUILD_BINARY_DIRECTORY}/BuildConfiguration.hpp")
cmake_path(SET RUNTIME_CONFIG_FILE "${BUILD_BINARY_DIRECTORY}/RuntimeConfiguration.hpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# CXX Compiler IDs
set(GCC_CXX_COMPILER "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_CXX_COMPILER "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# Executable build
set(${PROJECT_NAME}_ICON ${BUILD_ASSETS_DIRECTORY}/images/icon.icns)
# set(EXECUTABLE_OUTPUT_PATH ${BUILD_BINARY_DIRECTORY})




# ======================================================================================
# Load packages
# ======================================================================================

find_package(SDL2 2.26.2 REQUIRED)
find_package(spdlog 1.11.0 REQUIRED)
find_package(SDL2_ttf 2.20.1 REQUIRED)
find_package(SDL2_image 2.6.2 REQUIRED)
find_package(SDL2_mixer 2.6.2 REQUIRED)

# ======================================================================================
# Define the executable
# ======================================================================================

# Build the executable for each operating system
if(APPLE)
    set_source_files_properties(${${PROJECT_NAME}_ICON} PROPERTIES 
        MACOSX_PACKAGE_LOCATION "Resources"
        MACOSX_BUNDLE_ICON_FILE "${${PROJECT_NAME}_ICON}" 
    )
    add_executable(SXSW MACOSX_BUNDLE ${${PROJECT_NAME}_ICON}) 
elseif(WIN32)
    add_executable(SXSW WIN32)
endif()


target_include_directories(SXSW PUBLIC
    ${BUILD_BINARY_DIRECTORY}
    ${BUILD_SOURCE_DIRECTORY}
    ${SDL2_INCLUDE_DIR} 
    ${SDL2_IMAGE_INCLUDE_DIR} 
    ${SDL2_TTF_INCLUDE_DIR} 
    ${SDL2_MIXER_INCLUDE_DIR} 
    ${SPDLOG_INCLUDE_DIR} 
)

target_link_libraries(SXSW PRIVATE 
    SDL2::SDL2 
    SDL2_image::SDL2_image 
    SDL2_ttf::SDL2_ttf 
    SDL2_mixer::SDL2_mixer
    spdlog::spdlog
)


# Build source directory and link libraries
add_subdirectory(${BUILD_SOURCE_DIRECTORY})   
target_link_libraries(SXSW PRIVATE libEngine libSXSW)

# Set the compile options for the runtime build
target_compile_options(SXSW INTERFACE
    "$<${GCC_CXX_COMPILER}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
    "$<${MSVC_CXX_COMPILER}:$<BUILD_INTERFACE:-W3>>"
)

# ======================================================================================
# Write configuration files
# ======================================================================================

configure_file("${BUILD_CONFIG_FILE}.in" "${BUILD_CONFIG_FILE}")
configure_file("${RUNTIME_CONFIG_FILE}.in" "${RUNTIME_CONFIG_FILE}")


# include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
# set(CPACK_PACKAGE_VERSION_MAJOR "1")
# set(CPACK_PACKAGE_VERSION_MINOR "1")
# set(CPACK_SOURCE_GENERATOR "TGZ")
# include(CPack)