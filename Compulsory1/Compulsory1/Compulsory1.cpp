#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define _USE_MATH_DEFINES


#include <gl/GL.h>
#include <vector>

#include "OpenGlSettup.h"
#include "glm/ext/scalar_constants.hpp"

#include "Structs.h"

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"



using namespace std;



std::string readShader(const std::string& filename)
{
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}



void processInput(GLFWwindow *window);


// TriangleSurface::TriangleSurface()
// {
//     vertex v0{ 0,0,0, glm::vec3 (1.0f, 0.0f, 0.0f) };
//     vertex v1{ 1,0,0, glm::vec3 (0.0f, 1.0f, 0.0f) };
//     vertex v2{ 0,1,0, glm::vec3 (0.0f, 0.0f, 1.0f) };
//     mVertices.push_back(v0);
//     mVertices.push_back(v1);
//     mVertices.push_back(v2);
// }


// std::string vertexShaders = readShader("VertexShader.vert");
// std::string fragmentShaders = readShader("FragmentShader.frag");


// const char *vertexSource = vertexShaders.c_str();
// const char *fragmentSource = fragmentShaders.c_str();

const char *vertexSource =
    "#version 330 core\n"
    "layout(location = 0) in vec3 aPos;\n"
    "layout(location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(aPos, 1.0);\n"
    "ourColor = aColor;\n"
    "}\n";
    
const char *fragmentSource =
    "#version 330 core\n"
    "in vec3 ourColor;\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(ourColor, 1.0f);\n"
    "}\n";


int main()
{
   

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
    glBufferData(GL_ARRAY_BUFFER, points.size()* sizeof(vertex), points.data(), GL_STATIC_DRAW);

    
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
    
    glfwTerminate();
    CreateDataFile();
    
    return 0;
}


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}