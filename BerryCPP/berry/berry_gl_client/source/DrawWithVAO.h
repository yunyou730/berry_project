#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"
#include "Renderer.h"
#include "VertexBuffer.h"

/*
 Draw with simple VAO ,VBO
*/
namespace berry
{
    class DrawWithVAO : public DrawTestcaseBase
    {
    public:
        ~DrawWithVAO();

        virtual void Prepare() override;
        virtual void Renderer() override;

    private:
        GLuint    m_vao = 0;
        float*    m_vertice = nullptr;
        
        berry::VertexBuffer*   m_vertexBuffer = nullptr;
    };

}
