/**
 * @file lit.frag
 * @brief Fragment shader implementing Phong lighting model
 * 
 * This shader implements the Phong lighting model with ambient, diffuse,
 * and specular components. It's a fundamental lighting technique in 3D graphics.
 * 
 * Learning Resources:
 * - Phong Reflection Model: https://learnopengl.com/Lighting/Basic-Lighting
 * - Materials: https://learnopengl.com/Lighting/Materials
 * - Multiple Lights: https://learnopengl.com/Lighting/Multiple-lights
 */

#version 330 core

// Input from vertex shader
in vec3 FragPos;    // Fragment position in world space
in vec3 Normal;     // Normal vector in world space
in vec2 TexCoord;   // Texture coordinate

// Output color
out vec4 FragColor;

// Light properties
uniform vec3 lightPos;      // Light position in world space
uniform vec3 lightColor;    // Light color
uniform vec3 viewPos;       // Camera/viewer position in world space

// Material properties
uniform vec3 objectColor;   // Base color of the object
uniform float ambientStrength;   // Ambient light strength (default: 0.1)
uniform float specularStrength;  // Specular highlight strength (default: 0.5)
uniform float shininess;         // Shininess factor (default: 32)

void main()
{
    // Normalize the normal vector (may have been interpolated)
    vec3 norm = normalize(Normal);
    
    // === AMBIENT LIGHTING ===
    // Constant ambient light that illuminates all objects equally
    vec3 ambient = ambientStrength * lightColor;
    
    // === DIFFUSE LIGHTING ===
    // Calculate diffuse lighting based on angle between normal and light direction
    // Objects facing the light are brighter
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);  // Clamp to [0,1]
    vec3 diffuse = diff * lightColor;
    
    // === SPECULAR LIGHTING ===
    // Calculate specular highlights based on view angle
    // Creates shiny reflections
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  // Reflect light around normal
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * lightColor;
    
    // === COMBINE ALL COMPONENTS ===
    // Final color = (ambient + diffuse + specular) * object color
    vec3 result = (ambient + diffuse + specular) * objectColor;
    
    FragColor = vec4(result, 1.0);
}
