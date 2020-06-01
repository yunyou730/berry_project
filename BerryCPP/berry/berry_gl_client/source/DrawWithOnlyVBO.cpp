#include "DrawWithOnlyVBO.h"
#include "Shader.h"
#include "Renderer.h"

DrawWithOnlyVBO::~DrawWithOnlyVBO()
{
	delete[] m_vertice;
	glDeleteBuffers(1, &m_vbo);
	m_vbo = 0;
}

void DrawWithOnlyVBO::Prepare()
{
	m_vertice = new float[6];
	m_vertice[0] = -1.0f;
	m_vertice[1] = -1.0f;
	m_vertice[2] = -0.5f;
	m_vertice[3] = -0.5f;
	m_vertice[4] =  0.0f;
	m_vertice[5] = -1.0f;
    
    GLCALL(glGenBuffers(1, &m_vbo));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_vbo));
    GLCALL(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, m_vertice, GL_STATIC_DRAW));
    GLCALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 2, 0));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void DrawWithOnlyVBO::Renderer(berry::Renderer* renderer)
{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_vbo));
    GLCALL(glEnableVertexAttribArray(0));
    m_shader->Bind();

    GLCALL(glDrawArrays(GL_TRIANGLES, 0, 3));

    m_shader->Unbind();
    GLCALL(glDisableVertexAttribArray(0));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
