#pragma once

#include <string>
#include <gl/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/// <summary>
/// Creates a shaderID so the program and shader can be linked.
/// Calls a constructor class so that the external shader code can be loaded in and compiled.
/// A set function to select the correct shader for openGL to use.
/// Creates a matrix that can be updated for rendering
/// </summary>
class Shader 
{
public:
    GLuint shaderID; 

    Shader(const char* vertexPath, const char* fragmentPath);

    void set();

    void setMatrix(const std::string& name, const GLfloat* value) const;

    ~Shader();
};
