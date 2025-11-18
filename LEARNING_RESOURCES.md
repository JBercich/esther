# Learning Resources for SDL3 and OpenGL Game Development

This document provides a curated collection of learning resources for game development with C++, SDL3, and OpenGL. Resources are organized by topic and skill level.

## 📚 Table of Contents
- [C++ Fundamentals](#c-fundamentals)
- [Build Systems (CMake)](#build-systems-cmake)
- [SDL3 - Window and Input](#sdl3---window-and-input)
- [OpenGL - Graphics Programming](#opengl---graphics-programming)
- [Shaders (GLSL)](#shaders-glsl)
- [Game Development Patterns](#game-development-patterns)
- [Math for Game Development](#math-for-game-development)
- [Debugging and Tools](#debugging-and-tools)
- [Community and Forums](#community-and-forums)

---

## C++ Fundamentals

### Essential C++ (For Beginners)
- **LearnCpp.com** - https://www.learncpp.com/
  - Comprehensive C++ tutorial from basics to advanced
  - Free, well-organized, regularly updated
  - Start here if new to C++

- **C++ Reference** - https://en.cppreference.com/
  - Complete reference for C++ standard library
  - Essential bookmark for all C++ developers

- **Modern C++ Features** - https://github.com/AnthonyCalandra/modern-cpp-features
  - C++11, C++14, C++17, C++20 features explained
  - Important for understanding modern C++ code

### C++ Best Practices
- **C++ Core Guidelines** - https://isocpp.github.io/CppCoreGuidelines/
  - Official guidelines for writing good C++ code
  - Maintained by C++ standards committee

- **Awesome Modern C++** - https://github.com/rigtorp/awesome-modern-cpp
  - Curated list of frameworks, libraries, and resources

### Video Courses
- **Cherno's C++ Series** - https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb
  - Excellent video series covering C++ for game development
  - Practical and game-focused

---

## Build Systems (CMake)

### CMake Basics
- **CMake Official Tutorial** - https://cmake.org/cmake/help/latest/guide/tutorial/index.html
  - Official step-by-step tutorial
  - Start here for CMake fundamentals

- **Modern CMake** - https://cliutils.gitlab.io/modern-cmake/
  - Best practices for CMake 3.x
  - Clear examples and explanations

- **CMake Cookbook** - https://github.com/dev-cafe/cmake-cookbook
  - Practical CMake recipes
  - Solutions to common problems

### Video Tutorials
- **CMake Tutorial for Beginners** - https://www.youtube.com/watch?v=nlKcXPUJGwA
  - Video introduction to CMake concepts

---

## SDL3 - Window and Input

### SDL3 Documentation
- **SDL3 Wiki** - https://wiki.libsdl.org/SDL3/
  - Official documentation for SDL3
  - API reference and guides

- **SDL3 Migration Guide** - https://github.com/libsdl-org/SDL/blob/main/docs/README-migration.md
  - Differences from SDL2 to SDL3
  - Important if coming from SDL2

### SDL Tutorials
- **Lazy Foo's SDL Tutorials** - https://lazyfoo.net/tutorials/SDL/
  - Comprehensive SDL tutorial series (SDL2, but concepts apply)
  - Covers window creation, events, rendering, etc.

- **SDL Game Development** (Book)
  - By Shaun Mitchell
  - Practical game development with SDL

### Video Resources
- **SDL2 Tutorial Series** - https://www.youtube.com/watch?v=QQzAHcojEKg
  - Video tutorials on SDL (applicable to SDL3)

---

## OpenGL - Graphics Programming

### Getting Started
- **LearnOpenGL.com** - https://learnopengl.com/
  - **THE BEST** resource for learning modern OpenGL
  - Comprehensive, clear, well-structured
  - Start here for OpenGL!

- **OpenGL Documentation** - https://www.khronos.org/opengl/wiki/
  - Official OpenGL wiki and reference
  - Essential for looking up specifics

### OpenGL Fundamentals (Follow in Order)
1. **Getting Started** - https://learnopengl.com/Getting-started/OpenGL
   - OpenGL overview and setup
   
2. **Creating a Window** - https://learnopengl.com/Getting-started/Creating-a-window
   - Window creation and context setup
   
3. **Hello Triangle** - https://learnopengl.com/Getting-started/Hello-Triangle
   - Your first rendered geometry
   
4. **Shaders** - https://learnopengl.com/Getting-started/Shaders
   - Introduction to vertex and fragment shaders
   
5. **Textures** - https://learnopengl.com/Getting-started/Textures
   - Loading and applying textures
   
6. **Transformations** - https://learnopengl.com/Getting-started/Transformations
   - Model, view, projection matrices
   
7. **Coordinate Systems** - https://learnopengl.com/Getting-started/Coordinate-Systems
   - Understanding 3D space
   
8. **Camera** - https://learnopengl.com/Getting-started/Camera
   - Implementing a movable camera

### Advanced OpenGL
- **Lighting** - https://learnopengl.com/Lighting/Basic-Lighting
  - Phong lighting model
  - Multiple light sources
  
- **Model Loading** - https://learnopengl.com/Model-Loading/Assimp
  - Loading 3D models from files
  
- **Advanced OpenGL** - https://learnopengl.com/Advanced-OpenGL/Depth-testing
  - Depth testing, stencil testing, blending, etc.

### Video Resources
- **The Cherno OpenGL Series** - https://www.youtube.com/playlist?list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2
  - Excellent video series on OpenGL
  
- **Thin Matrix 3D Game Tutorial** - https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
  - Complete 3D game engine from scratch

---

## Shaders (GLSL)

### Shader Programming
- **The Book of Shaders** - https://thebookofshaders.com/
  - Interactive introduction to fragment shaders
  - Beautiful visual explanations
  
- **LearnOpenGL Shaders** - https://learnopengl.com/Getting-started/Shaders
  - Practical GLSL tutorial
  
- **GLSL Language Specification** - https://www.khronos.org/registry/OpenGL/specs/gl/GLSLangSpec.4.60.pdf
  - Official language specification
  - Reference for syntax and built-in functions

### Shader Resources
- **ShaderToy** - https://www.shadertoy.com/
  - Community shader showcase
  - Learn from others' code
  - Experiment with shaders in browser

- **GLSL Sandbox** - http://glslsandbox.com/
  - Another browser-based shader playground

### Video Tutorials
- **Shader Programming Introduction** - https://www.youtube.com/watch?v=kfM-yu0iQBk
  - Video introduction to shader programming

---

## Game Development Patterns

### Design Patterns
- **Game Programming Patterns** - https://gameprogrammingpatterns.com/
  - Essential book (free online)
  - Patterns specifically for game development
  - **Highly recommended**

### Architecture
- **Game Loop** - https://gameprogrammingpatterns.com/game-loop.html
  - Understanding the core game loop
  
- **Fix Your Timestep** - https://gafferongames.com/post/fix_your_timestep/
  - Critical article on game timing
  - Must-read for game loops

### Entity Component System (ECS)
- **ECS Introduction** - https://austinmorlan.com/posts/entity_component_system/
  - Modern game architecture pattern
  
- **EnTT Library** - https://github.com/skypjack/entt
  - Popular C++ ECS library

---

## Math for Game Development

### Linear Algebra
- **3D Math Primer for Graphics and Game Development** (Book)
  - Comprehensive math for 3D graphics
  
- **Essence of Linear Algebra** - https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab
  - Beautiful video series explaining linear algebra
  - 3Blue1Brown channel

### GLM Library (OpenGL Mathematics)
- **GLM Documentation** - https://github.com/g-truc/glm
  - Header-only C++ math library for OpenGL
  - Essential for matrices and vectors

### Tutorials
- **Coordinate Systems Explained** - https://learnopengl.com/Getting-started/Coordinate-Systems
  - Understanding different coordinate spaces
  
- **Transformations** - https://learnopengl.com/Getting-started/Transformations
  - Translation, rotation, scaling

---

## Debugging and Tools

### Debugging Graphics
- **RenderDoc** - https://renderdoc.org/
  - Frame debugger for graphics
  - Essential for debugging rendering issues
  
- **Nsight Graphics** - https://developer.nvidia.com/nsight-graphics
  - NVIDIA's graphics debugging tool

### Profiling
- **Tracy Profiler** - https://github.com/wolfpld/tracy
  - Real-time frame profiler
  - Great for finding performance bottlenecks

### Logging
- **spdlog** - https://github.com/gabime/spdlog
  - Fast C++ logging library
  - Used in this project

---

## Community and Forums

### Where to Get Help
- **LearnOpenGL Discord** - https://discord.gg/6s462Tw
  - Active community for OpenGL learners
  
- **/r/opengl** - https://www.reddit.com/r/opengl/
  - Reddit community for OpenGL
  
- **/r/gamedev** - https://www.reddit.com/r/gamedev/
  - General game development community
  
- **/r/cpp_questions** - https://www.reddit.com/r/cpp_questions/
  - Help with C++ questions
  
- **Stack Overflow** - https://stackoverflow.com/
  - Programming Q&A (tag: opengl, c++, sdl3)
  
- **SDL Discourse** - https://discourse.libsdl.org/
  - Official SDL forum

### Blogs and Articles
- **Gaffer On Games** - https://gafferongames.com/
  - Excellent articles on game networking, physics
  
- **Real-Time Rendering Resources** - https://www.realtimerendering.com/
  - Graphics programming resources

---

## Learning Path Recommendations

### Absolute Beginner
1. Learn C++ basics (LearnCpp.com)
2. Understand CMake basics (official tutorial)
3. Learn SDL3 window/event handling (SDL wiki, Lazy Foo)
4. Start with OpenGL (LearnOpenGL.com - Getting Started)
5. Understand game loops (Game Programming Patterns)

### Intermediate
1. Complete LearnOpenGL.com Lighting section
2. Implement your own Shader class
3. Learn about ECS architecture
4. Implement resource management
5. Study Game Programming Patterns book

### Advanced
1. Implement advanced rendering (shadows, post-processing)
2. Learn about modern rendering techniques
3. Optimize performance with profiling
4. Study graphics papers and presentations
5. Contribute to open-source graphics projects

---

## Books Worth Buying

1. **"Game Programming Patterns"** by Robert Nystrom
   - Free online or buy to support
   - Essential design patterns
   
2. **"Real-Time Rendering"** by Tomas Akenine-Möller et al.
   - The graphics programming bible
   - Advanced but comprehensive
   
3. **"3D Math Primer for Graphics and Game Development"** by Fletcher Dunn
   - Math fundamentals explained well
   
4. **"OpenGL Programming Guide"** (The Red Book)
   - Official OpenGL guide
   
5. **"Game Engine Architecture"** by Jason Gregory
   - Comprehensive engine architecture

---

## Tips for Learning

### General Advice
- **Start small**: Don't try to build everything at once
- **Read code**: Study open-source game engines and examples
- **Break things**: Experiment and see what happens
- **Ask questions**: Communities are generally helpful
- **Build projects**: Best way to learn is by doing
- **Debug systematically**: Use logging and debugging tools
- **Document as you go**: Future you will thank you

### Learning OpenGL Specifically
1. Follow LearnOpenGL.com in order
2. Type out all code yourself (don't copy-paste)
3. Experiment with each example before moving on
4. Understand why each line of code is needed
5. Use RenderDoc to visualize what's happening
6. Start with 2D before attempting 3D
7. Master the basics before jumping to advanced topics

### Using These Resources
- Bookmark frequently used references
- Keep notes on what you learn
- Build a personal knowledge base
- Revisit fundamentals regularly
- Share what you learn with others

---

## Quick Reference Links

**Must-Read First:**
- LearnOpenGL.com: https://learnopengl.com/
- Game Programming Patterns: https://gameprogrammingpatterns.com/
- LearnCpp.com: https://www.learncpp.com/

**Essential References:**
- OpenGL Wiki: https://www.khronos.org/opengl/wiki/
- SDL3 Wiki: https://wiki.libsdl.org/SDL3/
- C++ Reference: https://en.cppreference.com/

**When Stuck:**
- LearnOpenGL Discord: https://discord.gg/6s462Tw
- Stack Overflow: https://stackoverflow.com/
- SDL Discourse: https://discourse.libsdl.org/

---

Happy Learning! 🚀

Remember: Everyone starts somewhere. Don't get discouraged if things seem difficult at first. Graphics programming has a steep learning curve, but it's incredibly rewarding. Take it one step at a time, and celebrate small victories along the way!
