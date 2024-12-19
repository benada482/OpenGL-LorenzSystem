#version 330 core

//Pass in particle positions and the mvp
layout(location = 0) in vec3 position; 
uniform mat4 MVP; 

//set particle size and calulate position relative to mvp
void main() 
{
    gl_Position = MVP * vec4(position, 1.0);
    gl_PointSize = 1.0; 
}