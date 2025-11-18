/**
 * @file basic.vert
 * @brief Basic vertex shader with MVP transformation
 * 
 * This is a simple vertex shader that transforms vertices from object space
 * to clip space using Model-View-Projection matrices.
 * 
 * Learning Resources:
 * - Coordinate Systems: https://learnopengl.com/Getting-started/Coordinate-Systems
 * - Transformations: https://learnopengl.com/Getting-started/Transformations
 */

#version 330 core

// Input vertex attributes
layout (location = 0) in vec3 aPosition;  // Vertex position in object space
layout (location = 1) in vec3 aColor;     // Vertex color

// Output to fragment shader
out vec3 vertexColor;  // Color to pass to fragment shader

// Transformation matrices (set via uniform)
uniform mat4 model;       // Model matrix: object space -> world space
uniform mat4 view;        // View matrix: world space -> view/camera space
uniform mat4 projection;  // Projection matrix: view space -> clip space

void main()
{
    // Transform vertex position: object space -> clip space
    // The transformations are applied right-to-left:
    // 1. model: Transform from object space to world space
    // 2. view: Transform from world space to camera/view space
    // 3. projection: Transform from view space to clip space
    gl_Position = projection * view * model * vec4(aPosition, 1.0);
    
    // Pass color to fragment shader (will be interpolated across the triangle)
    vertexColor = aColor;
}
