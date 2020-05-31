#include "Shader.h"
#include <iostream>
using namespace berry;

Shader::Shader(const std::string& path)
    :m_filePath(path)
    ,m_program(0)
{
    
}

Shader::~Shader()
{
    
}
    
void Shader::Bind() const
{
    
}

void Shader::Unbind() const
{
    
}
    
void Shader::SetUniform4f(const std::string& name,float v0,float v1,float v2,float v3)
{
    
}
    
unsigned int Shader::GetUniformLocation(const std::string& name)
{
    return 0;
}

bool Shader::CompileShader()
{
//    GLuint id = glCreateShader(type);
//    const char* src = source.c_str();
//    glShaderSource(id, 1, &src, nullptr);
//    glCompileShader(id);
//    int result;
//    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
//    if (!result)
//    {
//        int length = 0;
//        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
//        char* message = new char[length];
//        glGetShaderInfoLog(id, length, &length, message);
//        std::cout << "Shader " << (type == GL_VERTEX_SHADER ? "vertex shader":"fragment shader") << " compile error" << std::endl;
//        std::cout << message << std::endl;
//        delete[] message;
//
//        glDeleteShader(id);
//        return 0;
//    }
//    return id;
    return true;
}
