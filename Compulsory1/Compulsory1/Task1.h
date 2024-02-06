#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <fstream>

#define _USE_MATH_DEFINES

using namespace std;

#include <glm/glm.hpp>

#include <gl/GL.h>


double f(double x)
{
    return x * x ; 
}

// funksjonen f'(x) for oppgave 1
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

    for (int i = 0; i <= n; i++)
    {
        double x = a + i * h;
        double y = f(x);
        double z = 0;
        double yDerivative = fDerivative(x);
        string color = yDerivative > 0 ? "blue" : "red";
        file << x << " " << y << " "<< z<< " "<<color << endl;
    }

    file.close();
}
void DrawGraph(GLuint shaderProgram, GLuint VAO, vector<vertex> points)
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, points.size());
}


vector <vertex> vertices(int start,int end, float distance)
{
    vector <vertex> vertices;
    for (float i = start; i < end; i+= distance)
    {
        vertex vertex;
        vertex.x = i;
        vertex.y = f(i);
        vertex.z = 0.f;
        float yDerivative = fDerivative(vertex.x);
        
        if (yDerivative > 0)
        {vertex.color = glm::vec3(0.0f, 1.0f, 0.0f);}
        else
        {vertex.color = glm::vec3(1.0f, 0.0f, 0.0f);}
        
        
        vertices.push_back(vertex);
    }
    return vertices;
}