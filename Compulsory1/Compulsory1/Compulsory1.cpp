#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <gl/GL.h>


using namespace std;

void processInput(GLFWwindow *window);

// Task 1--------------------------------------------------------------------
double f(double x)
{
    return x * x * x - 9 * x * x + 23 * x - 15;
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
void DrawGraph()
{
    double a = 0.0f;
    double b = 10.0f;
    
    int n = 100;
    
    double h = (b - a) / n;
    


    for (int i = 0; i <= n; ++i)
    {
        double x = a + i * h;
        double y = f(x);
        
        double yDerivative = fDerivative(x);
        string color = yDerivative > 0 ? "red" : "blue";
        double vertecies[n] = { y};
        glDrawArrays( GL_LINE_STRIP,0, vertecies[n]);
    }
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
int main(int argc, char* argv[])
{
//---------------------------------------------------------------------Setup of OpenGl and glad
    int width= 800, height = 600;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;}
    glfwMakeContextCurrent(window);
    
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
std::cout << "Failed to initialize GLAD" << std::endl;
return -1;
    
}

    
    
    glViewport(0, 0, width, height);

    // unsigned int VBO;
    // glGenBuffers(1, &VBO);
    //
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//----------------------------------------------------------------------------End of setup
    while(!glfwWindowShouldClose(window))
    {
        //input
        processInput(window);

//Rendering commands here

glClearColor(0.498f, 1.0f, 0.831f, 1.f);
glClear(GL_COLOR_BUFFER_BIT);


        DrawGraph();

//------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
    }

//execute simple code here--------------------------------------------------------------

    glDrawArrays(GL_LINE_STRIP,0, 50);
  
    //CreateSpiral();
    CreatePlane();
    glfwTerminate();
    return 0;
}



void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}