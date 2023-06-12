# Library
# -------

# The engine library is built in this subdirectory as a separate entity from the
# game but can be used by the game itself as some wrapper package API for running
# a game with a set of engine data structure instances and resource managers. It
# uses the SDL2 suite of packages to ensure that a game instance does not need to
# worry about this functionality and can use some wrapping class to perform any
# actions associated with said packages.

add_library(${PROJECT_NAME_ENGINE} STATIC Engine.cpp Game.cpp)

target_include_directories(
    ${PROJECT_NAME_ENGINE}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
    PRIVATE
        ${SDL2_INCLUDE_DIR} 
        ${SDL2_IMAGE_INCLUDE_DIR} 
        ${SDL2_MIXER_INCLUDE_DIR} 
        ${SDL2_TTF_INCLUDE_DIR} 
        ${SPDLOG_INCLUDE_DIR} 
)

target_link_libraries(
    ${PROJECT_NAME_ENGINE} 
    PRIVATE
        SDL2::SDL2 
        SDL2_image::SDL2_image 
        SDL2_ttf::SDL2_ttf 
        SDL2_mixer::SDL2_mixer
        spdlog::spdlog
)

add_subdirectory(Core)
add_subdirectory(Utilities)
