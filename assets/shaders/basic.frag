/**
 * @file basic.frag
 * @brief Basic fragment shader with interpolated colors
 * 
 * This fragment shader receives interpolated color values from the vertex shader
 * and outputs them directly to the screen.
 * 
 * Learning Resources:
 * - Fragment Shaders: https://learnopengl.com/Getting-started/Shaders
 * - Color Theory: https://learnopengl.com/Getting-started/Hello-Triangle
 */

#version 330 core

// Input from vertex shader (interpolated across the triangle)
in vec3 vertexColor;

// Output color
out vec4 FragColor;

void main()
{
    // Output the interpolated color with full opacity
    // vec4 components are (red, green, blue, alpha)
    FragColor = vec4(vertexColor, 1.0);
}
