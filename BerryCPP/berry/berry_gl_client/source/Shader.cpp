#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Renderer.h"

using namespace berry;

Shader::Shader(const std::string& path)
    :m_filePath(path)
    ,m_program(0)
{
	if (LoadSource(m_filePath, m_source))
	{
		m_program = Create(m_source.vertex, m_source.fragment);
	}
}

Shader::~Shader()
{
	glDeleteShader(m_program);
}
    
void Shader::Bind() const
{
	glUseProgram(m_program);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}
    
void Shader::SetUniform1i(const std::string& name,int value)
{
    glUniform1i(GetUniformLocation(name),value);
}

void Shader::SetUniform1f(const std::string& name,float value)
{
	GLCALL(glUniform1f(GetUniformLocation(name), value));
}

void Shader::SetUniform4f(const std::string& name,float v0,float v1,float v2,float v3)
{
	GLCALL(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	int index = GetUniformLocation(name);
	GLCALL(glUniformMatrix4fv(index, 1, GL_FALSE, &matrix[0][0]));
}
    
int Shader::GetUniformLocation(const std::string& name)
{
    std::map<std::string,int>::iterator it = m_uniformPosMap.find(name);
    if(it != m_uniformPosMap.end())
    {
        return it->second;
    }
    int location = glGetUniformLocation(m_program,name.c_str());
    if(location == -1)
    {
        std::cout << "GetUnitformLocation can not find " << name << std::endl;
    }
    m_uniformPosMap.insert(std::make_pair(name,location));
    return location;
}

bool Shader::LoadSource(const std::string& path, ShaderSource& shaderSource)
{
	std::string source[(int)ShaderSourceType::Max];

	std::fstream fs;
	fs.open(path);
	if (!fs.is_open())
	{
		printf("open shader file %s failed\n", path.c_str());
		return false;
	}

	ShaderSourceType sourceType = ShaderSourceType::None;
	std::string str;
	while (getline(fs, str))
	{
		std::cout << str << std::endl;
		if (str.find("#shader") != std::string::npos)
		{
			if (str.find("vertex") != std::string::npos)
			{
				sourceType = ShaderSourceType::Vertex;
			}
			else if (str.find("fragment") != std::string::npos)
			{
				sourceType = ShaderSourceType::Fragment;
			}
		}
		else if (sourceType > ShaderSourceType::None&& sourceType <= ShaderSourceType::Max)
		{
			source[(int)sourceType] += str + "\n";
		}
	}
	fs.close();
	shaderSource.vertex = source[(int)ShaderSourceType::Vertex];
	shaderSource.fragment = source[(int)ShaderSourceType::Fragment];
	return true;
}

unsigned int Shader::Compile(GLuint type,const std::string& source)
{
	unsigned int shaderId = glCreateShader(type);

    const char* src = source.c_str();
    glShaderSource(shaderId, 1, &src, nullptr);
    glCompileShader(shaderId);
    int result;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        int length = 0;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];
        glGetShaderInfoLog(shaderId, length, &length, message);
        std::cout << "Shader " << (type == GL_VERTEX_SHADER ? "vertex shader":"fragment shader") << " compile error" << std::endl;
        std::cout << message << std::endl;
        delete[] message;

        glDeleteShader(shaderId);
        return 0;
    }
    return shaderId;
}


GLuint Shader::Create(const std::string& vertexShader, const std::string& fragmentShader)
{
	GLuint program = glCreateProgram();
	GLuint vs = Compile(GL_VERTEX_SHADER, vertexShader);
	GLuint fs = Compile(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

