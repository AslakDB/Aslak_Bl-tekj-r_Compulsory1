#include <iostream>
#include <glm/glm.hpp>
#include <vector>

using namespace std;
struct vertex 
{   
    float x, y, z;
    glm::vec3 color;
};

struct Line {
    std::vector<vertex> mVertices;
    glm::mat4 matrix;
};
struct TriangleSurface {
    std::vector<vertex> mVertices;
    glm::mat4 matrix;
    TriangleSurface();
};

struct MyIO {
    static std::string readShader(const char* sourceFile);
};

