# add_subdirectory(fsa)

# add the executable
add_executable(Pong main.cpp)

# link_directories(fsa)

# target_link_libraries(elr1 #target in which link
#   fsalib #library name
#   )

# add_library(fsalib #name
#    Machine.cpp #files
#    MachineState.hpp
#    )

#  target_include_directories(fsalib PUBLIC
#   ${CMAKE_CURRENT_SOURCE_DIR}
#   )



# # Define final executable
# FILE(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
# SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_BIN_DIR})
# ADD_EXECUTABLE (${PROJECT_NAME} ${SOURCES})
# MESSAGE ("-- Set executable build output to: ${PROJECT_BIN_DIR}")

# # Include packages (the included header files)
# TARGET_INCLUDE_DIRECTORIES (
#     ${PROJECT_NAME} 
#     PRIVATE 
#     ${SDL2_INCLUDE_DIR} 
#     ${SDL2_IMAGE_INCLUDE_DIR} 
#     ${SDL2_TTF_INCLUDE_DIR} 
#     ${SDL2_MIXER_INCLUDE_DIR} 
#     ${SPDLOG_INCLUDE_DIR} 
#     ${PROJECT_LIB_DIR}
# )

# # Library packages (the library definitions)
# TARGET_LINK_LIBRARIES (
#     ${PROJECT_NAME} 
#     PRIVATE 
#     SDL2::SDL2 
#     SDL2_image::SDL2_image 
#     SDL2_ttf::SDL2_ttf 
#     SDL2_mixer::SDL2_mixer
#     spdlog::spdlog
# )