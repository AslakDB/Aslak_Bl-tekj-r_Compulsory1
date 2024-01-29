#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <fstream>
#include <gl/GL.h>
#include <vector>
#include "Shaders.h"
#include "OpenGlSettup.h"

using namespace std;

void processInput(GLFWwindow *window);

// Task 1--------------------------------------------------------------------
double f(double x)
{
    return x *x ;
}



double fDerivative(double x)
{
    double h = 0.0001;
    return (f(x + h) - f(x)) / h;
}
void CreateDataFile()
{
    // defisjonsmengden for funksjonen f(x)
    double a = 0.0f;
    double b = 10.0f;
    
    int n = 100;
    
    double h = (b - a) / n;

    ofstream file("data.txt");

    file << n + 1 << endl;

    for (int i = 0; i <= n; ++i)
    {
        double x = a + i * h;
        double y = f(x);
        double yDerivative = fDerivative(x);
        string color = yDerivative > 0 ? "red" : "blue";
        file << x << " " << y << " " << color << endl;
    }

    file.close();
}
void DrawGraph(GLuint shaderProgram, GLuint vbo, GLuint VAO, GLint posAttrib)
{
   
}

// Task 2--------------------------------------------------------------------

double x(double t)
{
    return cos(t);
}
double y(double t)
{
    return sin(t);
}
double z(double t)
{
    return t;
}

void CreateSpiral()
{
    double a = 0.0f;
    double b = 10.0f;
    
    int n = 100;
    
    double h = (b - a) / n;

    ofstream file("spiral.txt");

    file << n + 1 << endl;

    for (int i = 0; i <= n; ++i)
    {
        double t = a + i * h;
        double x1 = x(t);
        double y1 = y(t);
        double z1 = z(t);
        file << x1 << " " << y1 << " " << z1 << endl;
    }
    
        file.close();
}
void DrawSpiral()
{
    
}
// Task 3--------------------------------------------------------------------
double g(double x, double y) {
    return x * x + y * y ;
}

void CreatePlane()
{
    std::ofstream file("Plane.txt");

    double a = -10.0f;
    double b = 10.0f;
    
    int n = 100;
    
    for (double i = -10; i <= n; i ++) {
        double x = g(a, b) * i / 10;
        double y = i / 10;
        double z = 0;
        file << x << " " << y << " " << z << endl;
    }

    file.close();
}
int n;

struct vertex 
{
   double x, y, z, w;
};
 

vector <vertex> vertices(int start,int end, float distance)
{
    vector <vertex> vertices;
    for (float i = start; i < end; i += distance)
    {
        vertex vertexies;
        vertexies.x = i ;
        vertexies.y = f(vertexies.x);
        vertexies.z = 0;
        vertices.push_back(vertexies);
    }
    return vertices;
}
int main(int argc, char* argv[])
{
    
//settup contructor
    Settup settup(2560 / 2, 1440 / 2, "Compulsory1");

    const char* vertexSource = 
"#version 330 core\n"
"in vec3 position;"
"void main()"
"{"
"    gl_Position = vec4(position, 1.0);"
"}";
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    
    
    // Create and compile the fragment shader
    const char* fragmentSource = 
        "#version 330 core\n"
        "out vec4 outColor;"
        "void main()"
        "{"
        "    outColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
        "}";
    
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Link the vertex and fragment shader into a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);

    
    vector<vertex> points = vertices(0, 1, 0.1f);
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, points.size()* sizeof(vertex), points.data(), GL_STATIC_DRAW);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),(void*) 0);
    glEnableVertexAttribArray(0);
    
    while(!glfwWindowShouldClose(settup.window))
    {
        //input here
        processInput(settup.window);

//Rendering commands here---------------------------------------------------------------------------------------------------------

glClearColor(0.498f, 1.0f, 0.831f, 1.f);
glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        glEnableVertexAttribArray(posAttrib);
        glDrawArrays(GL_LINE_STRIP, 0, points.size());

//------------------------------------------------------
    glfwSwapBuffers(settup.window);
    glfwPollEvents();
    }

//execute simple code here--------------------------------------------------------------

   
  CreateDataFile();
    //CreateSpiral();
    //CreatePlane();

   std::cout <<points.data() << std::endl;
   std::cout <<points.size() << std::endl;
    
    
    glfwTerminate();
    CreateDataFile();
    
    return 0;
}



void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}