/**
 * @file lit.vert
 * @brief Vertex shader for Phong lighting model
 * 
 * This vertex shader prepares data for Phong lighting calculations in the
 * fragment shader. It passes along normal vectors and fragment positions
 * in world space.
 * 
 * Learning Resources:
 * - Basic Lighting: https://learnopengl.com/Lighting/Basic-Lighting
 * - Phong Lighting: https://learnopengl.com/Lighting/Basic-Lighting
 */

#version 330 core

// Input vertex attributes
layout (location = 0) in vec3 aPosition;  // Vertex position
layout (location = 1) in vec3 aNormal;    // Vertex normal
layout (location = 2) in vec2 aTexCoord;  // Texture coordinate (optional)

// Output to fragment shader
out vec3 FragPos;      // Fragment position in world space
out vec3 Normal;       // Normal vector in world space
out vec2 TexCoord;     // Texture coordinate

// Transformation matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Calculate fragment position in world space
    FragPos = vec3(model * vec4(aPosition, 1.0));
    
    // Transform normal to world space
    // Note: Use normal matrix (inverse transpose of model) for non-uniform scaling
    Normal = mat3(transpose(inverse(model))) * aNormal;
    
    // Pass through texture coordinate
    TexCoord = aTexCoord;
    
    // Transform vertex to clip space
    gl_Position = projection * view * vec4(FragPos, 1.0);
}
