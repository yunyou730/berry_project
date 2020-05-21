#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <map>
#include <string>

namespace berry
{
	class ShaderManager
	{
	public:
		typedef enum 
		{
			VS_POS,
		} EVSShaderType;

		typedef enum EFSShaderType
		{
			FS_COLOR,
		} EFSShaderType;

		typedef enum 
		{
			SIMPLE_POS_COLOR,
		}EShaderProgram;

	public:
		static ShaderManager* Instance();
		~ShaderManager();

	private:
		ShaderManager();
	private:
		void InitBaseShaders();
		//GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

		GLuint CreateProgram(GLuint vsId,GLuint fsId);
		GLuint CompileShader(GLuint type, const std::string& source);


		void ClearVSShaders();
		void ClearFSShaders();
		void ClearPrograms();

	private:
		std::map<EVSShaderType, std::string>	m_vsSourceMap;
		std::map<EVSShaderType, GLuint>			m_vsShaderMap;

		std::map<EFSShaderType, std::string>	m_fsSourceMap;
		std::map<EFSShaderType, GLuint>			m_fsShaderMap;

		std::map<EShaderProgram, GLuint>		m_shaderProgramMap;
	};
}
