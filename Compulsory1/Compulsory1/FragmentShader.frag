#version 330 core

in vec3 newcolor;
out vec4 FragColor;

void main()
{
   FragColor = vec4(newcolor, 1.0f);
}