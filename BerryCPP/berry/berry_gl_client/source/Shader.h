#pragma once
#include <string>
#include <map>
#include <GL/glew.h>
#include "glm/glm.hpp"

namespace berry
{
    class Shader
    {
	private:

		struct ShaderSource
		{
			std::string vertex;
			std::string fragment;
		};

		enum class ShaderSourceType
		{
			None = -1,
			Vertex = 0,
			Fragment = 1,
			Max,
		};


    public:
        Shader(const std::string& path);
        ~Shader();
        
        void Bind() const;
        void Unbind() const;
        
        void SetUniform1i(const std::string& name,int value);
        void SetUniform1f(const std::string& name,float value);
        void SetUniform4f(const std::string& name,float v0,float v1,float v2,float v3);
        void SetUniformMat4f(const std::string& name,const glm::mat4& matrix);
        
    private:
        int GetUniformLocation(const std::string& name);
        GLuint Create(const std::string& vertexShader, const std::string& fragmentShader);
        bool LoadSource(const std::string& path, ShaderSource& shaderSource);
        unsigned int  Compile(GLuint type, const std::string& source);
        
    private:
        unsigned int m_program = 0;
        std::map<std::string,int> m_uniformPosMap;
        std::string m_filePath;
        ShaderSource    m_source;
    };

}
