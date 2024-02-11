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
    glm::vec3 color;
};

struct dataVertex
{
    float x, y, z;
    string color;
};


const char *vertexSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 newcolor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "   newcolor = aColor;\n"  
    "}\0";


const char *fragmentSource = "#version 330 core\n"
    "in vec3 newcolor;\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(newcolor, 1.0f);\n"
    "}\n\0";



void processInput(GLFWwindow *window);

// Task 1--------------------------------------------------------------------

// funksjonen f(x) for oppgave 1
double f(double x)
{
<<<<<<< HEAD
    return x *x ;
=======
    return - 2*x*x; 
>>>>>>> 7385905244f162c7b352ec25e93c098efc56ca64
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

// Task 3--------------------------------------------------------------------
double g(double x, double y) {
    return x * x + y * y ;
}



void CreatePlane()
{
    std::ofstream file("Plane.txt");
    
    int n = 10;
    
    for (float i = -10; i <= n; i ++) {
        for (int j = -10; j < n; j ++)
        {
            int x = i;
            int y = j;

            g(i, j);

            file<< x << " " << y << " " << g(i, j) << endl;
        }
    }

    file.close();
}

int main()
{
<<<<<<< HEAD
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
=======

    //change the bool to true to run the spiral or to run the graph. If it is true run the spiral, if it is false run the graph
    
    bool isSpiral = true;
    
//settup contructor
    Settup settup(2560 / 2, 1440 / 2, "Compulsory1");
    

    glLineWidth(6);
  vector<vertex> points = vertices(-10, 10, 0.01f);
    vector<vertex> points2 = spiralVertices();
>>>>>>> 7385905244f162c7b352ec25e93c098efc56ca64
    
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

    if (isSpiral)
    glBufferData(GL_ARRAY_BUFFER, points2.size()* sizeof(vertex), points2.data(), GL_STATIC_DRAW);
    else
    {
        glBufferData(GL_ARRAY_BUFFER, points.size()* sizeof(vertex), points.data(), GL_STATIC_DRAW);
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex) ,(void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 1);
    glBindVertexArray(1); 
    
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

//Rendering commands here----------------------------------------------------------------------------------------------------------------------------

glClearColor(0.498f, 1.0f, 0.831f, 1.f);
glClear(GL_COLOR_BUFFER_BIT);
        
<<<<<<< HEAD
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        glEnableVertexAttribArray(posAttrib);
        glDrawArrays(GL_LINE_STRIP, 0, points.size());
=======
        
        if (!isSpiral)
        DrawGraph(shaderProgram, VAO, points); //Task 1

        if (isSpiral)
        DrawSpiral(shaderProgram, VAO,points2); //Task 2
>>>>>>> 7385905244f162c7b352ec25e93c098efc56ca64

//------------------------------------------------------
    glfwSwapBuffers(settup.window);
    glfwPollEvents();
    }

//execute simple code here-------------------------------------------------------------------------------------------------------------------------------------


    //To generate the txt file for the task 1, uncomment the line below
    // CreateDataFile();

    //To generate the txt file for the task 2, uncomment the line below
    //CreateSpiral();

    //To generate the txt file for the task 3, uncomment the line below
    //CreatePlane();

<<<<<<< HEAD
   std::cout <<points.data() << std::endl;
   std::cout <<points.size() << std::endl;
=======
    

   

>>>>>>> 7385905244f162c7b352ec25e93c098efc56ca64
    
    
    glfwTerminate();
    CreateDataFile();
    
    return 0;
}



void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}