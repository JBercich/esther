add_subdirectory(Engine)
add_subdirectory(Esther)

target_include_directories(Esther PRIVATE Engine)
target_link_libraries(Esther PRIVATE Engine)