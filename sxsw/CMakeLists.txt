# ======================================================================================
# CMakeLists
# ======================================================================================
# Setup and build the main executable.
#   - Define build options and variables
#   - Load packages
#   - Define the executable
#   - Write configuration files
# ======================================================================================

cmake_minimum_required(VERSION 3.24.2)

project(SXSW LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Output build system information
message("-- Build system information")
message("---- System (${CMAKE_SYSTEM})")
message("---- System Name (${CMAKE_SYSTEM_NAME})")
message("---- System Version (${CMAKE_SYSTEM_VERSION})")
message("---- Host System Name (${CMAKE_HOST_SYSTEM_NAME})")
message("---- System Processor (${CMAKE_SYSTEM_PROCESSOR})")

# ======================================================================================
# Define build options and variables
# ======================================================================================

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

# Additional variables
set(SXSW_ICON ${BUILD_ASSETS_DIRECTORY}/images/icon.icns)
set(EXECUTABLE_OUTPUT_PATH ${BUILD_BINARY_DIRECTORY})
set(ADDITIONAL_PACKAGE_SEARCH_PATTERNS
    # Apple    
    # ~/Library/Frameworks
    # /Library/Frameworks
    # /usr/local
    # /opt/local
    # /opt/csw 
    # /usr
    # /opt
    # /sw 
)

# ======================================================================================
# Load packages
# ======================================================================================

find_package(SDL2 2.26.2 REQUIRED HINTS ADDITIONAL_PACKAGE_SEARCH_PATTERNS)
find_package(spdlog 1.11.0 REQUIRED HINTS ADDITIONAL_PACKAGE_SEARCH_PATTERNS)
find_package(SDL2_ttf 2.20.1 REQUIRED HINTS ADDITIONAL_PACKAGE_SEARCH_PATTERNS)
find_package(SDL2_image 2.6.2 REQUIRED HINTS ADDITIONAL_PACKAGE_SEARCH_PATTERNS)
find_package(SDL2_mixer 2.6.2 REQUIRED HINTS ADDITIONAL_PACKAGE_SEARCH_PATTERNS)

# ======================================================================================
# Define the executable
# ======================================================================================

if(APPLE)
    set_source_files_properties(
        ${SXSW_ICON}
        PROPERTIES 
        MACOSX_PACKAGE_LOCATION "Resources"
        MACOSX_BUNDLE_ICON_FILE "${SXSW_ICON}" 
    )
    add_executable(SXSW MACOSX_BUNDLE ${SXSW_ICON}) 
elseif(WIN32)
    add_executable(SXSW WIN32)
endif()

add_subdirectory(${BUILD_SOURCE_DIRECTORY})   
target_link_libraries(SXSW PRIVATE libEngine libSXSW)

# ======================================================================================
# Write configuration files
# ======================================================================================

configure_file("${BUILD_CONFIG_FILE}.in" "${BUILD_CONFIG_FILE}")
configure_file("${RUNTIME_CONFIG_FILE}.in" "${RUNTIME_CONFIG_FILE}")
