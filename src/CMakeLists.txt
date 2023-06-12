# Sources
# -------

# The split between the engine static library and game is connected here where the
# engine is linked to the game target as a separate library. Each respective 
# subdirectory is then recursed on to complete the CMake build.

add_subdirectory(${PROJECT_NAME_ENGINE})
add_subdirectory(${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME} 
    PRIVATE 
        ${PROJECT_NAME_ENGINE}
)

target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE 
        ${PROJECT_NAME_ENGINE}
)
