#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <sstream>
#include <glm/glm.hpp>
#include <fstream>
#include <gl/GL.h>
#include <vector>


using namespace std;

float x(float t)
{
    return cos(t);
}
float y(float t)
{
    return sin(t);
}


float z(float t)
{
    return t ;
}

void CreateSpiral()
{
    float a = 0.0f;
    float b = 10.0f;
    
    int n = 100;
    
    float h = (b - a) / n;

    ofstream file("spiral.txt");

    file << n + 1 << endl;

    for (int i = 0; i <= n; ++i)
    {
        float t = a + i * h;
        float x1 = x(t);
        float y1 = y(t);
        float z1 = z(t);
        float yDerivative = fDerivative(x1);
        string color = yDerivative > 0 ? "blue" : "red";
        
        file << x1 << " " << y1 << " " << z1  << " " << color<< endl;
    }
    
    file.close();
}
void DrawSpiral(GLuint shaderProgram, GLuint VAO, vector<vertex> points)
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, points.size());
}

vector<vertex> spiralVertices()
{
    vector<vertex> vertices;
    float angle;
    float distance = 1.f;
    
    for (angle = 0.5; angle  <= (360); angle += distance)
    {
        vertex vertex;
        
        vertex.x = angle * 0.01 ;
        vertex.y = y(angle / M_PI) * 0.1; 
        vertex.z =x(angle /M_PI )* 0.1 ;
        float yDerivative = fDerivative(vertex.y);
        
        if (yDerivative > 0)
        {vertex.color = glm::vec3(0.0f, 1.0f, 0.0f);}
        else
        {vertex.color = glm::vec3(1.0f, 0.0f, 0.0f);}
        
        vertices.push_back(vertex);
    }
    return vertices;
}