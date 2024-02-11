#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <sstream>

#include <fstream>
#include <gl/GL.h>


using namespace std;


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