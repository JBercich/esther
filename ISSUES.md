# Issues for SDL3 and OpenGL Game Engine Setup

This document contains detailed specifications for all issues related to the "SDL3 and OpenGL Game Engine Setup" milestone. Each issue includes learning resources, acceptance criteria, and implementation guidance.

---

## Issue #1: Set up CMake build system with SDL3 integration

### Description
Configure the CMake build system to properly find, link, and integrate SDL3 library. This is the foundation for the entire project and must handle cross-platform builds correctly.

### Learning Resources
- **CMake Official Tutorial**: https://cmake.org/cmake/help/latest/guide/tutorial/index.html
- **Modern CMake Practices**: https://cliutils.gitlab.io/modern-cmake/
- **SDL3 Migration Guide**: https://github.com/libsdl-org/SDL/blob/main/docs/README-migration.md
- **CMake find_package documentation**: https://cmake.org/cmake/help/latest/command/find_package.html
- **Video: CMake Tutorial for Beginners**: https://www.youtube.com/watch?v=nlKcXPUJGwA

### Tasks
- [ ] Update CMakeLists.txt to require CMake 3.20+
- [ ] Add SDL3 as a dependency using `find_package` or FetchContent
- [ ] Configure include directories for SDL3 headers
- [ ] Link SDL3 libraries to the main executable
- [ ] Test build on target platform (macOS initially)
- [ ] Add error handling for missing SDL3 installation
- [ ] Document SDL3 installation instructions in README

### Acceptance Criteria
- Project builds successfully with `cmake ..` and `make`
- SDL3 headers are found and included correctly
- Linker successfully links SDL3 libraries
- Build errors provide clear messages if SDL3 is not found
- CMake generates appropriate build files for the platform

### Logging Requirements
- Log CMake configuration step showing SDL3 found/not found
- Document any build warnings or errors encountered

### Implementation Notes
```cmake
# Example CMake snippet
find_package(SDL3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
```

---

## Issue #2: Configure OpenGL context and shader pipeline

### Description
Set up OpenGL context creation through SDL3 and establish the basic infrastructure for loading and using GLSL shaders. This includes setting up GLAD or similar loader for OpenGL functions.

### Learning Resources
- **LearnOpenGL - Getting Started**: https://learnopengl.com/Getting-started/OpenGL
- **OpenGL Context Creation**: https://learnopengl.com/Getting-started/Creating-a-window
- **Modern OpenGL Tutorial**: https://open.gl/context
- **GLAD Loader Documentation**: https://glad.dav1d.de/
- **SDL OpenGL Integration**: https://wiki.libsdl.org/SDL3/CategoryVideo
- **OpenGL Shaders Basics**: https://learnopengl.com/Getting-started/Shaders
- **Video: OpenGL Modern Tutorial**: https://www.youtube.com/watch?v=W3gAzLwfIP0

### Tasks
- [ ] Research OpenGL version selection (recommend OpenGL 3.3 Core Profile)
- [ ] Add GLAD or similar OpenGL loader to project
- [ ] Configure SDL3 to create OpenGL context with correct attributes
- [ ] Initialize OpenGL function pointers
- [ ] Set up basic OpenGL state (viewport, clear color)
- [ ] Create abstraction for OpenGL context management
- [ ] Add error checking for OpenGL calls
- [ ] Test that OpenGL context is created successfully

### Acceptance Criteria
- SDL3 window creates valid OpenGL context
- OpenGL version matches requested version (3.3+)
- GLAD successfully loads all required OpenGL functions
- Can make basic OpenGL calls (glClear, glViewport)
- Error handling catches and reports OpenGL errors
- Context is properly cleaned up on exit

### Logging Requirements
- Log OpenGL version and renderer information
- Log any context creation errors
- Log shader compilation status (in later issues)

### Implementation Notes
```cpp
// Example SDL OpenGL setup
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
```

---

## Issue #3: Implement logging system (spdlog integration)

### Description
Integrate spdlog library for comprehensive logging throughout the application. Logging should support multiple levels (trace, debug, info, warn, error) and be configurable for different build types.

### Learning Resources
- **spdlog GitHub Repository**: https://github.com/gabime/spdlog
- **spdlog Wiki**: https://github.com/gabime/spdlog/wiki
- **Logging Best Practices**: https://www.loggly.com/ultimate-guide/c-logging-basics/
- **C++ Logging Frameworks Comparison**: https://www.codeproject.com/Articles/1272619/spdlog-vs-log4cplus-vs-Boost-log-vs-Pantheios
- **Video: Logging in C++**: https://www.youtube.com/watch?v=oEx5vGNFrLk

### Tasks
- [ ] Add spdlog as a dependency in CMakeLists.txt
- [ ] Create logging wrapper/utility class
- [ ] Configure log levels for debug vs release builds
- [ ] Set up file and console logging sinks
- [ ] Create logging macros for easy use (LOG_INFO, LOG_ERROR, etc.)
- [ ] Add timestamps and thread IDs to log messages
- [ ] Configure log file rotation and size limits
- [ ] Document logging usage and best practices

### Acceptance Criteria
- spdlog builds and links correctly
- Logging works in both console and file
- Different log levels can be set at runtime
- Log messages include timestamps and context
- Performance impact is minimal (asynchronous logging preferred)
- Logs are human-readable and useful for debugging

### Logging Requirements
- Log application startup and shutdown
- Log all major system initializations (SDL3, OpenGL)
- Log errors with stack traces where possible
- Log performance metrics (frame time, etc.)

### Implementation Notes
```cpp
// Example logging usage
#include <spdlog/spdlog.h>

void initLogging() {
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%#] %v");
}

// Usage
spdlog::info("SDL3 initialized successfully");
spdlog::error("Failed to load shader: {}", filename);
```

---

## Issue #4: Create basic window and rendering loop

### Description
Implement the core game loop with SDL3 event handling, frame timing, and basic rendering. This establishes the foundation for all future rendering and game logic.

### Learning Resources
- **Game Loop Pattern**: https://gameprogrammingpatterns.com/game-loop.html
- **Fix Your Timestep**: https://gafferongames.com/post/fix_your_timestep/
- **SDL Event Handling**: https://wiki.libsdl.org/SDL3/CategoryEvents
- **Game Loop Tutorial**: https://bell0bytes.eu/the-game-loop/
- **Video: Game Loop Explained**: https://www.youtube.com/watch?v=yGhfUcPjXuE

### Tasks
- [ ] Create main game loop structure
- [ ] Implement SDL event processing (quit, keyboard, mouse)
- [ ] Add frame timing and delta time calculation
- [ ] Implement FPS counter and limiter
- [ ] Create window with configurable size and title
- [ ] Add basic input handling structure
- [ ] Implement graceful shutdown sequence
- [ ] Clear window with color each frame

### Acceptance Criteria
- Window opens and displays correctly
- Event loop processes quit events (ESC key, window close)
- Frame timing is consistent and measurable
- Application runs at stable frame rate (60 FPS target)
- CPU usage is reasonable (not 100% busy-wait)
- Clean shutdown with no memory leaks
- Logs show frame timing and event processing

### Logging Requirements
- Log window creation parameters
- Log FPS at regular intervals (every 5 seconds)
- Log all critical events (quit, errors)
- Log frame time spikes (> 33ms)

### Implementation Notes
```cpp
// Example game loop structure
bool running = true;
while (running) {
    // Process events
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            running = false;
        }
    }
    
    // Update game state
    // deltaTime calculation here
    
    // Render
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
}
```

---

## Issue #5: Add shader compilation and management system

### Description
Create a robust system for loading, compiling, and managing GLSL shaders. This should include error handling, shader reloading, and a simple interface for using shaders.

### Learning Resources
- **LearnOpenGL - Shaders**: https://learnopengl.com/Getting-started/Shaders
- **OpenGL Shader Compilation**: https://www.khronos.org/opengl/wiki/Shader_Compilation
- **GLSL Language Specification**: https://www.khronos.org/opengl/wiki/OpenGL_Shading_Language
- **Shader Error Handling**: https://www.lighthouse3d.com/tutorials/glsl-tutorial/debugging-shaders/
- **Video: OpenGL Shaders Tutorial**: https://www.youtube.com/watch?v=kMcJNL3TXZ8

### Tasks
- [ ] Create Shader class for managing individual shaders
- [ ] Implement shader source loading from files
- [ ] Add shader compilation with error checking
- [ ] Implement shader program linking
- [ ] Create utility functions for setting uniforms
- [ ] Add shader hot-reloading during development
- [ ] Implement shader validation and debugging
- [ ] Document shader API and usage

### Acceptance Criteria
- Shaders compile from source files successfully
- Compilation errors show file, line number, and description
- Shader programs link correctly
- Can set uniform variables easily (mat4, vec3, int, float)
- Shader class manages OpenGL resources correctly (no leaks)
- Hot-reload works during development
- Clear error messages for shader issues

### Logging Requirements
- Log shader compilation status (success/failure)
- Log shader compilation errors with full details
- Log shader program linking status
- Log uniform locations and types
- Log shader reload events

### Implementation Notes
```cpp
// Example Shader class interface
class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    void setUniform(const std::string& name, const glm::mat4& value);
    void setUniform(const std::string& name, const glm::vec3& value);
    bool reload();
private:
    GLuint programID;
    bool compileShader(GLenum type, const std::string& source);
};
```

---

## Issue #6: Set up resource management for assets

### Description
Create a system for loading and managing game assets (shaders, textures, models). This should handle file paths, resource caching, and memory management.

### Learning Resources
- **Resource Management Patterns**: https://gameprogrammingpatterns.com/object-pool.html
- **C++ File I/O**: https://www.cplusplus.com/doc/tutorial/files/
- **std::filesystem**: https://en.cppreference.com/w/cpp/filesystem
- **Asset Pipeline Design**: https://www.gamedeveloper.com/programming/sponsored-designing-a-modern-gpu-based-asset-pipeline

### Tasks
- [ ] Create assets directory structure (shaders/, textures/, etc.)
- [ ] Implement file path utilities using std::filesystem
- [ ] Create ResourceManager class for caching
- [ ] Add text file loading for shaders
- [ ] Implement relative path resolution
- [ ] Add error handling for missing files
- [ ] Create asset manifest or registry system
- [ ] Document asset organization guidelines

### Acceptance Criteria
- Assets load from organized directory structure
- File not found errors are clear and actionable
- Resource manager prevents duplicate loading
- Paths work consistently across platforms
- Memory usage is tracked and reasonable
- Resources are cleaned up properly on exit

### Logging Requirements
- Log asset loading success/failure
- Log asset paths being searched
- Log resource cache hits/misses
- Log memory usage for loaded resources

### Implementation Notes
```cpp
// Example resource path handling
#include <filesystem>
namespace fs = std::filesystem;

fs::path getAssetPath(const std::string& relative) {
    return fs::current_path() / "assets" / relative;
}
```

---

## Issue #7: Create example shaders (vertex and fragment)

### Description
Create working example shaders that demonstrate basic rendering techniques. Include well-commented code explaining each part for learning purposes.

### Learning Resources
- **LearnOpenGL - Shaders**: https://learnopengl.com/Getting-started/Shaders
- **The Book of Shaders**: https://thebookofshaders.com/
- **ShaderToy (for inspiration)**: https://www.shadertoy.com/
- **GLSL Reference**: https://www.khronos.org/opengl/wiki/OpenGL_Shading_Language
- **Video: Shader Basics**: https://www.youtube.com/watch?v=kfM-yu0iQBk

### Tasks
- [ ] Create basic vertex shader (pass-through with transformations)
- [ ] Create basic fragment shader (simple color output)
- [ ] Add uniform support for color/transformation
- [ ] Create shader with lighting (Phong or Blinn-Phong)
- [ ] Add example shader with textures
- [ ] Comment all shader code extensively
- [ ] Create shader documentation with visual examples
- [ ] Test all shaders render correctly

### Acceptance Criteria
- All example shaders compile without errors
- Shaders demonstrate key concepts (MVP matrix, lighting, textures)
- Comments explain every significant line
- Shaders are optimized and follow best practices
- Visual output matches expectations
- Shaders work on target OpenGL version (3.3+)

### Logging Requirements
- Log which shaders are being used
- Log shader switch events
- Log any runtime shader errors

### Example Shaders to Create
1. **basic.vert** - Simple vertex shader with MVP transformation
2. **basic.frag** - Simple fragment shader with solid color
3. **colored.vert** - Vertex shader with color attributes
4. **colored.frag** - Fragment shader interpolating vertex colors
5. **lit.vert** - Vertex shader for lighting calculations
6. **lit.frag** - Fragment shader with Phong lighting

---

## Issue #8: Documentation and learning resources compilation

### Description
Create comprehensive documentation covering the entire setup, usage, and extension of the game engine. Include learning paths for developers new to C++, SDL3, or OpenGL.

### Learning Resources
- **Writing Great Documentation**: https://www.writethedocs.org/guide/writing/beginners-guide-to-docs/
- **Markdown Guide**: https://www.markdownguide.org/
- **Doxygen Documentation**: https://www.doxygen.nl/manual/index.html
- **C++ Best Practices**: https://github.com/cpp-best-practices/cppbestpractices

### Tasks
- [ ] Update README.md with complete setup instructions
- [ ] Create BUILDING.md with platform-specific build steps
- [ ] Write ARCHITECTURE.md explaining code organization
- [ ] Create SHADERS.md tutorial on shader development
- [ ] Add API documentation using Doxygen
- [ ] Create troubleshooting guide for common issues
- [ ] Compile learning resources into LEARNING.md
- [ ] Add code examples for common tasks

### Acceptance Criteria
- Documentation is clear and beginner-friendly
- All code examples work correctly
- Build instructions verified on target platform
- API documentation generated successfully
- Learning paths guide from beginner to advanced
- Troubleshooting covers common issues
- Documentation is kept up-to-date with code

### Document Structure
```
docs/
├── BUILDING.md          # Build instructions
├── ARCHITECTURE.md      # System design overview
├── SHADERS.md          # Shader development guide
├── API.md              # API reference
├── LEARNING.md         # Learning resources
└── TROUBLESHOOTING.md  # Common issues and solutions
```

### Logging Requirements
- Document logging API and usage
- Explain log levels and when to use them
- Show examples of good logging practices

---

## Implementation Order

For best results, implement issues in this order:
1. Issue #3 (Logging) - Enables debugging of subsequent work
2. Issue #1 (CMake/SDL3) - Foundation for everything else
3. Issue #2 (OpenGL Context) - Required for rendering
4. Issue #4 (Game Loop) - Framework for testing rendering
5. Issue #6 (Resource Management) - Needed for loading shaders
6. Issue #5 (Shader System) - Core rendering capability
7. Issue #7 (Example Shaders) - Demonstrates the system working
8. Issue #8 (Documentation) - Captures everything learned

## Tips for Implementation
- Commit frequently with clear messages
- Test each component thoroughly before moving on
- Use logging extensively during development
- Refer back to learning resources when stuck
- Don't hesitate to ask questions in issue comments
- Celebrate small wins - each issue completed is progress!

## Getting Help
- OpenGL/Graphics: LearnOpenGL.com community, /r/opengl
- C++: /r/cpp_questions, Stack Overflow
- SDL: SDL Discourse forum
- CMake: CMake Discourse forum
