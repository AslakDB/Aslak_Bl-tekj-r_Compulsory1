#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <fstream>
#include <gl/GL.h>

struct shaders
{
public:

    // const char* vertexSource = 
    // "#version 150 core\n"
    // "in vec2 position;"
    // "void main()"
    // "{"
    // "    gl_Position = vec4(position, 0.0, 1.0);"
    // "}";
    // GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1, &vertexSource, NULL);
    // glCompileShader(vertexShader);
    //
    // // Create and compile the fragment shader
    // const char* fragmentSource = 
    //     "#version 150 core\n"
    //     "out vec4 outColor;"
    //     "void main()"
    //     "{"
    //     "    outColor = vec4(1.0, 1.0, 1.0, 1.0);"
    //     "}";
    //
    // GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    // glCompileShader(fragmentShader);
    //
    // // Link the vertex and fragment shader into a shader program
    // GLuint shaderProgram = glCreateProgram();
    // glAttachShader(shaderProgram, vertexShader);
    // glAttachShader(shaderProgram, fragmentShader);
    // glLinkProgram(shaderProgram);
    // glUseProgram(shaderProgram);
    //
    //
    // GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    // glEnableVertexAttribArray(posAttrib);
    // glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
};
