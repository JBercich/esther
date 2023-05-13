# add_subdirectory (Engine)
# add_subdirectory (Game)
# add_subdirectory (Pong)



# SET (EXECUTABLE_OUTPUT_PATH ../../bin)
# message("${filepath}")
# TARGET_INCLUDE_DIRECTORIES (Pong PRIVATE filepath)


project(Pong VERSION 0.0.1 LANGUAGES CXX)
project(SXSW VERSION 0.0.1 LANGUAGES CXX)

set(EXECUTABLE_OUTPUT_PATH ${SOURCE_BINARY_DIR})

add_executable(Pong Pong/main.cpp)
add_executable(SXSW SXSW/main.cpp)


# Set additional search paths for locating certain packages for Apple builds
# set(APPLE_PACKAGE_SEARCH_PATTERNS 
    # ~/Library/Frameworks
    # /Library/Frameworks
    # /usr/local
    # /opt/local
    # /opt/csw 
    # /usr
    # /opt
    # /sw 
# )