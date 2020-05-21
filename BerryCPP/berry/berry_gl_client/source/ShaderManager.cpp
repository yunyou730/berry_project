#include "ShaderManager.h"
#include <string>
#include <iostream>

using namespace berry;

static const std::string vs_pos = 
"#version 330 core\n"
"\n"
"layout(location = 0) in vec4 position;"
"\n"
"void main()\n"
"{\n"
"	gl_Position = position;\n"
"}\n";

static const std::string fs_color = 
"#version 330 core\n"
"\n"
"layout(location = 0) out vec4 color;"
"\n"
"void main()\n"
"{\n"
"	color = vec4(1.0,0.0,0.0,1.0);\n"
"}\n";


ShaderManager::ShaderManager()
{
	InitBaseShaders();
}

ShaderManager::~ShaderManager()
{
	ClearPrograms();
	ClearVSShaders();
	ClearFSShaders();
}

ShaderManager* ShaderManager::Instance()
{
	static ShaderManager instance;
	return &instance;
}

void ShaderManager::InitBaseShaders()
{
	// vs source
	m_vsSourceMap.insert(std::make_pair(EVSShaderType::VS_POS, vs_pos));

	// fs source
	m_fsSourceMap.insert(std::make_pair(EFSShaderType::FS_COLOR,fs_color));

	// vs shaders
	for (auto it:m_vsSourceMap)
	{
		EVSShaderType vsType = it.first;
		const std::string& source = it.second;
		GLuint vsId = CompileShader(GL_VERTEX_SHADER, source);
		m_vsShaderMap.insert(std::make_pair(vsType,vsId));
	}

	// fs shaders
	for (auto it : m_fsSourceMap)
	{
		EFSShaderType fsType = it.first;
		const std::string& source = it.second;
		GLuint fsId = CompileShader(GL_FRAGMENT_SHADER, source);
		m_fsShaderMap.insert(std::make_pair(fsType, fsId));
	}

	// programs
	GLuint programId = CreateProgram(m_vsShaderMap[EVSShaderType::VS_POS], m_fsShaderMap[FS_COLOR]);
	m_shaderProgramMap.insert(std::make_pair(EShaderProgram::SIMPLE_POS_COLOR,programId));
}

GLuint ShaderManager::CreateProgram(GLuint vsId, GLuint fsId)
{
	GLuint programId = glCreateProgram();
	glAttachShader(programId,vsId);
	glAttachShader(programId,fsId);
	glLinkProgram(programId);
	glValidateProgram(programId);
	return programId;
}

//GLuint ShaderManager::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
//{
//	GLuint program = glCreateProgram();
//	GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
//	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
//
//	glAttachShader(program, vs);
//	glAttachShader(program, fs);
//	glLinkProgram(program);
//	glValidateProgram(program);
//
//	glDeleteShader(vs);
//	glDeleteShader(fs);
//
//	return program;
//}


GLuint ShaderManager::CompileShader(GLuint type, const std::string& source)
{
	GLuint id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		int length = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Shader " << (type == GL_VERTEX_SHADER ? "vertex shader" : "fragment shader") << " compile error" << std::endl;
		std::cout << message << std::endl;
		delete[] message;

		glDeleteShader(id);
		return 0;
	}
	return id;
}

void ShaderManager::ClearVSShaders()
{
	m_vsSourceMap.clear();
	for (auto it: m_vsShaderMap)
	{
		GLuint shaderId = it.second;
		glDeleteShader(shaderId);
	}
	m_vsShaderMap.clear();
}

void ShaderManager::ClearFSShaders()
{
	m_fsSourceMap.clear();
	for (auto it:m_fsShaderMap)
	{
		GLuint	shaderId = it.second;
		glDeleteShader(shaderId);
	}
	m_fsShaderMap.clear();
}

void ShaderManager::ClearPrograms()
{
	for (auto it: m_shaderProgramMap)
	{
		GLuint programId = it.second;
		glDeleteProgram(programId);
	}
	m_shaderProgramMap.clear();
}