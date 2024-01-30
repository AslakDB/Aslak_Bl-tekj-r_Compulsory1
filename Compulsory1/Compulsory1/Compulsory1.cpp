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
#include "Shaders.h"
#include "OpenGlSettup.h"
#include "glm/ext/scalar_constants.hpp"

using namespace std;
struct vertex 
{   
   float x, y, z;
};

struct dataVertex
{
    float x, y, z;
    string color;
};


const char *vertexSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


void processInput(GLFWwindow *window);

// Task 1--------------------------------------------------------------------
double f(double x)
{
    return x * x*x - 2 * x*x;
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

    for (int i = 0; i <= n; i++)
    {
        double x = a + i * h;
        double y = f(x);
        double z = 0;
        double yDerivative = fDerivative(x);
        string color = yDerivative > 0 ? "red" : "blue";
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
        vertices.push_back(vertex);
    }
    return vertices;
}
// Task 2--------------------------------------------------------------------

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
        file << x1 << " " << y1 << " " << z1 << endl;
    }
    
        file.close();
}
void DrawSpiral(GLuint shaderProgram, GLuint VAO, vector<vertex> points)
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, points.size());
}
// Task 3--------------------------------------------------------------------
double g(double x, double y) {
    return x * x + y * y ;
}

vector<dataVertex> readfromfile()
{
    vector<dataVertex> points;
    ifstream file("Data.txt");

    if (!file.is_open())
    {
        cout << "Error opening file";
        exit(-1);
    }
    
        string line;

    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        dataVertex dataVertex;
        ss >> dataVertex.x >> dataVertex.y >> dataVertex.z >> dataVertex.color;
        points.push_back(dataVertex);
    }
    
        file.close();
    return points;
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
        
        double z =+ 0.5;
        file << x << " " << y << " " << z << endl;
    }

    file.close();
}

vector<vertex> spiralVertices()
{
    vector<vertex> vertices;
    double a = 0.0f;
    double b = 10.0f;
    
    int n = 100;
    
    double h = (b - a) /n;
    float angle;
    int numberOfSpirals = 24;
    float distance = 1.f;
    
    for (angle = 0.5; angle  <= (360); angle += distance)
    {
        vertex vertex;
        double t = b - angle;
        vertex.x = angle * 0.01 ;
        vertex.y = y(angle / M_PI) * 0.1; 
        vertex.z =x(angle /M_PI )* 0.1 ;
        vertices.push_back(vertex);
    }
    return vertices;
}



int main()
{
    
//settup contructor
    Settup settup(2560 / 2, 1440 / 2, "Compulsory1");
    

    glLineWidth(3);
  vector<vertex> points = vertices(-10, 10, 0.01f);
    vector<vertex> points2 = spiralVertices();
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    
    
    // Create and compile the fragment shader
 
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
    // GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    // glEnableVertexAttribArray(posAttrib);
    // glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
    
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, points2.size()* sizeof(vertex), points2.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0); 
    
    while(!glfwWindowShouldClose(settup.window))
    {
        //input here
        processInput(settup.window);

//Rendering commands here---------------------------------------------------------------------------------------------------------

glClearColor(0.498f, 1.0f, 0.831f, 1.f);
glClear(GL_COLOR_BUFFER_BIT);
        //DrawGraph(shaderProgram, VAO, points); //Task 1
        DrawSpiral(shaderProgram, VAO,points2); //Task 2

//------------------------------------------------------
    glfwSwapBuffers(settup.window);
    glfwPollEvents();
    }

//execute simple code here--------------------------------------------------------------

   
  CreateDataFile();
    //CreateSpiral();
    //CreatePlane();

    

   

    
    
    glfwTerminate();
    CreateDataFile();
    return 0;
}



void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}