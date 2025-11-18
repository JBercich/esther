# Shaders

This directory contains GLSL shaders for the Esther game engine.

## Shader Files

### Basic Shaders
- **basic.vert** - Simple vertex shader with MVP transformation
- **basic.frag** - Simple fragment shader with interpolated colors

These shaders demonstrate the fundamental concepts of vertex and fragment shaders:
- Transforming vertices from object space to clip space
- Passing data from vertex to fragment shader
- Outputting colors

### Lighting Shaders
- **lit.vert** - Vertex shader for Phong lighting
- **lit.frag** - Fragment shader implementing Phong lighting model

These shaders implement the Phong lighting model with three components:
- **Ambient**: Constant base lighting
- **Diffuse**: Lighting based on surface angle to light source
- **Specular**: Shiny highlights based on view angle

## Using Shaders

To use these shaders in your application:

1. Load the shader files from this directory
2. Compile them using the Shader class (see Issue #5)
3. Set uniform variables (matrices, light positions, etc.)
4. Activate the shader before drawing

Example:
```cpp
Shader shader("assets/shaders/basic.vert", "assets/shaders/basic.frag");
shader.use();
shader.setUniform("model", modelMatrix);
shader.setUniform("view", viewMatrix);
shader.setUniform("projection", projectionMatrix);
```

## Learning Resources

- **LearnOpenGL Shaders**: https://learnopengl.com/Getting-started/Shaders
- **The Book of Shaders**: https://thebookofshaders.com/
- **GLSL Reference**: https://www.khronos.org/opengl/wiki/OpenGL_Shading_Language
- **OpenGL Shader Language Specification**: https://www.khronos.org/registry/OpenGL/specs/gl/GLSLangSpec.4.60.pdf

## Shader Development Tips

1. **Start Simple**: Begin with basic.vert and basic.frag to understand the pipeline
2. **Use Logging**: Log shader compilation errors - they contain valuable debugging info
3. **Test Incrementally**: Make small changes and test frequently
4. **Check Uniforms**: Ensure all uniforms are set before drawing
5. **Validate Input**: Make sure vertex attributes match shader expectations
6. **Hot Reload**: Implement shader hot-reloading for faster iteration

## Common Issues

### Shader Won't Compile
- Check GLSL version matches your OpenGL context (3.3 core)
- Verify all variable declarations have types
- Ensure main() function exists
- Check for missing semicolons

### Black Screen
- Verify uniforms are set correctly
- Check that matrices are not identity/zero
- Ensure vertex data is being sent correctly
- Verify shader is activated with `shader.use()`

### Lighting Looks Wrong
- Ensure normals are normalized
- Check light position is in world space
- Verify view position is set correctly
- Test with ambient-only lighting first

## Creating New Shaders

When creating new shaders:

1. Copy an existing shader as a template
2. Update the version directive (`#version 330 core`)
3. Document what the shader does (comments at top)
4. List input attributes and their locations
5. Document uniform variables and their purposes
6. Add learning resource links in comments
7. Test thoroughly with different inputs

## Shader Naming Convention

- Use descriptive names: `basic`, `lit`, `textured`, `particle`, etc.
- Use `.vert` for vertex shaders
- Use `.frag` for fragment shaders
- Keep matching pairs together (same prefix)
