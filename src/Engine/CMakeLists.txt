# Engine library requires packages
add_library(libEngine STATIC GameEngine.cpp)

target_include_directories(libEngine PUBLIC
    ${BUILD_BINARY_DIRECTORY}
    ${BUILD_SOURCE_DIRECTORY}
    ${SDL2_INCLUDE_DIR} 
    ${SDL2_IMAGE_INCLUDE_DIR} 
    ${SDL2_TTF_INCLUDE_DIR} 
    ${SDL2_MIXER_INCLUDE_DIR} 
    ${SPDLOG_INCLUDE_DIR} 
)

target_link_libraries(libEngine PUBLIC 
    SDL2::SDL2 
    SDL2_image::SDL2_image 
    SDL2_ttf::SDL2_ttf 
    SDL2_mixer::SDL2_mixer
    spdlog::spdlog
)

# add_subdirectory(ECS)
add_subdirectory(Manager)
add_subdirectory(Utilities)
