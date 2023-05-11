# =============================================================================
# cmake definition for automated makefile generation.
#   Handles creating a comprehensive makefile for the project depending on the
#   arguments from this configuration. 
# =============================================================================

MESSAGE ("- Generating cmake environment")

# Define project dirs
SET (PROJECT_BIN_DIR bin)
SET (PROJECT_INC_DIR inc)
SET (PROJECT_LIB_DIR lib)
SET (PROJECT_SRC_DIR src)
SET (PROJECT_BUILD_DIR build)
SET (PROJECT_AUDIO_DIR audio)
SET (PROJECT_ASSETS_DIR assets)
SET (EXEC_SRC ${PROJECT_SRC_DIR}/main.cpp)
SET (METADATA_FILE ${PROJECT_BIN_DIR}/cmake.ini)

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

# Describe system
MESSAGE ("-- Reading running operating system")
MESSAGE ("--- name \t -> \t ${CMAKE_SYSTEM_NAME}")
MESSAGE ("--- version \t -> \t ${CMAKE_SYSTEM_VERSION}")
MESSAGE ("--- processor \t -> \t ${CMAKE_SYSTEM_PROCESSOR}")
MESSAGE ("--- hostname \t -> \t ${CMAKE_HOST_SYSTEM_NAME}")
MESSAGE ("--- tagname \t -> \t ${CMAKE_SYSTEM}")

# System-specific actions
IF (UNIX)
    # TODO: perform relevant system operations
ELSEIF (APPLE)
    # TODO: perform relevant system operations
ELSEIF (WIN32)
    # TODO: perform relevant system operations
ENDIF ()

# =============================================================================

# Contain cmake level constants e.g. OS and versioning
CONFIGURE_FILE (lib/CmakeConfig.hpp.in lib/CmakeConfig.hpp)

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

# Process packages
MESSAGE ("-- Setting up project packages")

# For managing runtime logging
FIND_PACKAGE (spdlog 1.11.0 REQUIRED HINTS PACKAGE_SEARCH_PATHS)
# For handling application windows
FIND_PACKAGE (SDL2 2.26.2 REQUIRED HINTS PACKAGE_SEARCH_PATHS)
# For manaing fonts and font families for rendering
FIND_PACKAGE (SDL2_ttf 2.20.1 REQUIRED HINTS PACKAGE_SEARCH_PATHS)
# For manaing image rendering
FIND_PACKAGE (SDL2_image 2.6.2 REQUIRED HINTS PACKAGE_SEARCH_PATHS)
# For manaing audio loading and playing
FIND_PACKAGE (SDL2_mixer 2.6.2 REQUIRED HINTS PACKAGE_SEARCH_PATHS)

SET (
    PROJECT_PACKAGES 
    spdlog
    SDL2 
    SDL2_ttf 
    SDL2_image 
    SDL2_mixer
)

FOREACH (PACKAGE ${PROJECT_PACKAGES})
    IF (${${PACKAGE}_FOUND})
        MESSAGE ("--- ${PACKAGE} \t -> \t [${${PACKAGE}_VERSION}]")
    ELSE ()
        MESSAGE(FATAL_ERROR "${PACKAGE} not found")
    ENDIF ()
ENDFOREACH ()

# =============================================================================

# Cmake compile command
# SET (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define final executable
FILE(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_BIN_DIR})
ADD_EXECUTABLE (${PROJECT_NAME} ${SOURCES})
MESSAGE ("-- Set executable build output to: ${PROJECT_BIN_DIR}")

# Include packages (the included header files)
TARGET_INCLUDE_DIRECTORIES (
    ${PROJECT_NAME} 
    PRIVATE 
    ${SDL2_INCLUDE_DIR} 
    ${SDL2_IMAGE_INCLUDE_DIR} 
    ${SDL2_TTF_INCLUDE_DIR} 
    ${SDL2_MIXER_INCLUDE_DIR} 
    ${SPDLOG_INCLUDE_DIR} 
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
    spdlog::spdlog
)

# =============================================================================

# Compiler setup
SET (GCC_COMPILER_CXX "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
SET (MSVC_COMPILER_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# See https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wpedantic")
SET (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
SET (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
TARGET_COMPILE_OPTIONS (${PROJECT_NAME} INTERFACE
    "$<${GCC_COMPILER_CXX}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wpedantic;-Wformat=2;-Wunused>>"
    "$<${MSVC_COMPILER_CXX}:$<BUILD_INTERFACE:-W3>>"
)

STRING (COMPARE EQUAL "${CMAKE_BUILD_TYPE}" "Release" CHECK_RELEASE)
STRING (COMPARE EQUAL "${CMAKE_BUILD_TYPE}" "Debug" CHECK_DEBUG)
IF (NOT CHECK_RELEASE)
    IF (NOT CHECK_DEBUG)
        SET (CMAKE_BUILD_TYPE "Debug")
    ENDIF ()
ENDIF ()

MESSAGE ("-- Selected build type and compiler flags: ${CMAKE_BUILD_TYPE}")
MESSAGE ("--- Base \t -> \t  ${CMAKE_CXX_FLAGS}")
MESSAGE ("--- Debug \t -> \t  ${CMAKE_CXX_FLAGS_DEBUG}")
MESSAGE ("--- Release \t -> \t  ${CMAKE_CXX_FLAGS_RELEASE}")

# =============================================================================

# Write down a cmake metadata file for the compilation to track system info
FILE (WRITE ${METADATA_FILE} "")
FILE (APPEND ${METADATA_FILE} "[cmake]\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_VERSION=${CMAKE_VERSION}\n")
FILE (APPEND ${METADATA_FILE} "EXECUTABLE_SOURCE=${EXEC_SRC}\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}\n\n")

FILE (APPEND ${METADATA_FILE} "[cmake.packages]\n")
FOREACH (PACKAGE ${PROJECT_PACKAGES})
    FILE (APPEND ${METADATA_FILE} "${PACKAGE}=${${PACKAGE}_VERSION}\n")
ENDFOREACH ()
FILE (APPEND ${METADATA_FILE} "\n")

FILE (APPEND ${METADATA_FILE} "[cmake.compiler]\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_CXX_FLAGS_DEBUG=${CMAKE_CXX_FLAGS_DEBUG}\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_CXX_FLAGS_RELEASE=${CMAKE_CXX_FLAGS_RELEASE}\n\n")

FILE (APPEND ${METADATA_FILE} "[project]\n")
FILE (APPEND ${METADATA_FILE} "PROJECT_NAME=${PROJECT_NAME}\n")
FILE (APPEND ${METADATA_FILE} "PROJECT_VERSION=${PROJECT_VERSION}\n\n")

FILE (APPEND ${METADATA_FILE} "[system]\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME}\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_SYSTEM_VERSION=${CMAKE_SYSTEM_VERSION}\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_SYSTEM_PROCESSOR=${CMAKE_SYSTEM_PROCESSOR}\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_HOST_SYSTEM_NAME=${CMAKE_HOST_SYSTEM_NAME}\n")
FILE (APPEND ${METADATA_FILE} "CMAKE_SYSTEM=${CMAKE_SYSTEM}\n\n")

# =============================================================================






