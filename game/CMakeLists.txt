# =============================================================================
# cmake definition for automated makefile generation.
#   Handles creating a comprehensive makefile for the project depending on the
#   arguments from this configuration. 
# =============================================================================

# Define cmake environment
CMAKE_MINIMUM_REQUIRED (VERSION 3.24.2)

# Handle NEW versioning definition
IF (POLICY CMP0048) # https://github.com/Tencent/rapidjson/issues/1154
    CMAKE_POLICY (SET CMP0048 NEW)
ENDIF (POLICY CMP0048)

# Set compiler for cxx
SET (CMAKE_CXX_STANDARD 20)
SET (CMAKE_CXX_STANDARD_REQUIRED True)

# =============================================================================

PROJECT (Game VERSION 0.1.0 LANGUAGES CXX) # NOTE: update version

# =============================================================================

# Contain cmake level constants e.g. OS and versioning
CONFIGURE_FILE (lib/GameConfig.h.in lib/GameConfig.h)

# Define project dirs
SET (PROJECT_BIN_DIR bin)
SET (PROJECT_INC_DIR inc)
SET (PROJECT_LIB_DIR lib)
SET (PROJECT_SRC_DIR src)
SET (PROJECT_BUILD_DIR build)
SET (PROJECT_AUDIO_DIR audio)
SET (PROJECT_ASSETS_DIR assets)
SET (EXEC_SRC ${PROJECT_SRC_DIR}/main.cpp)

# Search patterns for finding packages
SET (
    PACKAGE_SEARCH_PATHS 
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local
    /opt/local
    /opt/csw 
    /usr
    /opt
    /sw 
)

# Find packages to be used
FIND_PACKAGE (SDL2 2.26.2 REQUIRED HINTS PACKAGE_SEARCH_PATHS)
MESSAGE ("-- SDL2 version ${SDL2_VERSION}")
FIND_PACKAGE (SDL2_ttf 2.20.1 REQUIRED HINTS PACKAGE_SEARCH_PATHS)
MESSAGE ("-- SDL2_ttf version ${SDL2_ttf_VERSION}")
FIND_PACKAGE (SDL2_image 2.6.2 REQUIRED HINTS PACKAGE_SEARCH_PATHS)
MESSAGE ("-- SDL2_image version ${SDL2_image_VERSION}")
FIND_PACKAGE (SDL2_mixer 2.6.2 REQUIRED HINTS PACKAGE_SEARCH_PATHS)
MESSAGE ("-- SDL2_mixer version ${SDL2_mixer_VERSION}")

IF (NOT SDL2_FOUND)
    ERROR ("SDL2 package not found")
ELSEIF (NOT SDL2_ttf_FOUND)
    ERROR ("SDL2_ttf package not found")
ELSEIF (NOT SDL2_image_FOUND)
    ERROR ("SDL2_image package not found")
ELSEIF (NOT SDL2_mixer_FOUND)
    ERROR ("SDL2_mixer package not found")
ENDIF ()


# =============================================================================

# System-specific actions
IF (UNIX)
    MESSAGE ("-- Operating system ${CMAKE_SYSTEM_NAME}")
ELSEIF (APPLE)
    MESSAGE ("-- Operating system ${CMAKE_SYSTEM_NAME}")
ELSEIF (WIN32)
    MESSAGE ("-- Operating system ${CMAKE_SYSTEM_NAME}")
ENDIF ()

# =============================================================================


# Define final executable
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_BIN_DIR})
ADD_EXECUTABLE (${PROJECT_NAME} ${EXEC_SRC})

# Include packages (the included header files)
TARGET_INCLUDE_DIRECTORIES (
    ${PROJECT_NAME} 
    PRIVATE 
    ${SDL2_INCLUDE_DIR} 
    ${SDL2_IMAGE_INCLUDE_DIR} 
    ${SDL2_TTF_INCLUDE_DIR} 
    ${SDL2_MIXER_INCLUDE_DIR} 
    ${PROJECT_LIB_DIR}
)

# Library packages (the library definitions)
TARGET_LINK_LIBRARIES (
    ${PROJECT_NAME} 
    PRIVATE 
    SDL2::SDL2 
    SDL2_image::SDL2_image 
    SDL2_ttf::SDL2_ttf 
    SDL2_mixer::SDL2_mixer
)

# Build type should be defined
SET (GCC_COMPILER_CXX "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
SET (MSVC_COMPILER_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")


MESSAGE ("-- Build type ${CMAKE_BUILD_TYPE}")
TARGET_COMPILE_OPTIONS (${PROJECT_NAME} INTERFACE
  "$<${GCC_COMPILER_CXX}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${MSVC_COMPILER_CXX}:$<BUILD_INTERFACE:-W3>>"
)
# install(TARGETS ${PROJECT_SRC_DIR} DESTINATION ${PROJECT_BIN_DIR})

# See https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html
# SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wpedantic")
# SET (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
# SET (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
