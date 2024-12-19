#include "Shader.h"

/// <summary>
/// Loads the shader code as strings, then compiles them to make them run within the context and then links them to the program so that they are selected.
/// After each stage there is a check to ensure that the shaders have loaded correctly.
/// </summary>
/// <param name="vertexPath">The file path of the vertex shader</param>
/// <param name="fragmentPath">The file path of the fragment shader</param>
Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    // Load vertex shader and set up exception detection for open errors
    std::string vertexCode;
    std::ifstream vertShaderFile;
    vertShaderFile.exceptions(std::ifstream::failbit);
    try 
    {
        vertShaderFile.open(vertexPath);
        std::stringstream vShaderStream;
        vShaderStream << vertShaderFile.rdbuf();
        vertShaderFile.close();
        vertexCode = vShaderStream.str();
    }
    catch (std::ifstream::failure& e) {
        std::cerr << "ERROR: Vertex shader cannot be read" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();

    //Load fragment shader
    std::string fragmentCode;
    std::ifstream fragShaderFile;
    fragShaderFile.exceptions(std::ifstream::failbit);
    try 
    {
        fragShaderFile.open(fragmentPath);
        std::stringstream fShaderStream;
        fShaderStream << fragShaderFile.rdbuf();
        fragShaderFile.close();
        fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure& e)
    {
        std::cerr << "ERROR: Fragment shader cannot be read" << std::endl;
    }
    const char* fShaderCode = fragmentCode.c_str();

    GLint result = GL_FALSE;
    int infoLogLength;

    //Vertex shader compiler & check it runs
    GLuint vertexShaderID;
    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vShaderCode, NULL);
    glCompileShader(vertexShaderID);
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (!result) 
    {
        std::vector<char> VertexShaderErrorMessage(infoLogLength + 1);
        glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }

    //Fragment shader compiler & check it runs
    GLuint fragmentShaderID;
    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderID, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShaderID);
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
    if (!result) 
    {
        std::vector<char> FragmentShaderErrorMessage(infoLogLength + 1);
        glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        printf("%s\n", &FragmentShaderErrorMessage[0]);
    }

    //Linking program
    shaderID = glCreateProgram();
    glAttachShader(shaderID, vertexShaderID);
    glAttachShader(shaderID, fragmentShaderID);
    glLinkProgram(shaderID);
    glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
    if (!result) 
    {
        std::vector<char> ShaderErrorMessage(infoLogLength + 1);
       glGetShaderInfoLog(shaderID, infoLogLength, NULL, &ShaderErrorMessage[0]);
        printf("%s\n", &ShaderErrorMessage[0]);
    }

    glDetachShader(shaderID, vertexShaderID);
    glDetachShader(shaderID, fragmentShaderID);

    // Delete shaders
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

}

/// <summary>
/// Assigns the shader program for the GPU to use for rendering 
/// </summary>
void Shader::set() 
{
    glUseProgram(shaderID);
}

/// <summary>
/// Passes a matrix to the shader so that the GPU can handle vertex transforms to ensure rendering happens in the correct place.
/// </summary>
/// <param name="name">Variable name within BasicVert shader</param>
/// <param name="value">Stores matrix to send to shader</param>
void Shader::setMatrix(const std::string& varName, const GLfloat* matVal) const 
{
    glUniformMatrix4fv(glGetUniformLocation(shaderID, varName.c_str()), 1, GL_FALSE, matVal);
}

/// <summary>
/// Deletes shaderID variable to free memory
/// </summary>
Shader::~Shader() {
    glDeleteProgram(shaderID);
}