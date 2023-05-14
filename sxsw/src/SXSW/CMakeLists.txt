target_sources(SXSW PRIVATE main.cpp)

add_library(libSXSW STATIC test.cpp)

target_include_directories(libSXSW PUBLIC
    ${BUILD_BINARY_DIRECTORY}
    ${BUILD_SOURCE_DIRECTORY}
    ${SDL2_INCLUDE_DIR} 
    ${SDL2_IMAGE_INCLUDE_DIR} 
    ${SDL2_TTF_INCLUDE_DIR} 
    ${SDL2_MIXER_INCLUDE_DIR} 
    ${SPDLOG_INCLUDE_DIR} 
)

target_link_libraries(libSXSW PRIVATE 
    SDL2::SDL2 
    SDL2_image::SDL2_image 
    SDL2_ttf::SDL2_ttf 
    SDL2_mixer::SDL2_mixer
    spdlog::spdlog
)

