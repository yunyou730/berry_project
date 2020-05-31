#pragma once
#include <string>
#include <map>
#include <GL/glew.h>

namespace berry
{
    class Shader
    {
    public:
        Shader(const std::string& path);
        ~Shader();
        
        void Bind() const;
        void Unbind() const;
        
        void SetUniform4f(const std::string& name,float v0,float v1,float v2,float v3);
        
    private:
        unsigned int GetUniformLocation(const std::string& name);
        bool CompileShader();
        
    private:
        unsigned int m_program = 0;
        std::map<std::string,unsigned int> m_uniformPosMap;
        std::string m_filePath;
    };

}
