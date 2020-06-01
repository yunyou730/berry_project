#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

/*
 Draw with simple VAO,VBO,EBO
*/
class DrawWithEBO : public berry::DrawTestcaseBase
{
public:
	~DrawWithEBO();

	virtual void Prepare() override;
	virtual void Renderer(berry::Renderer* renderer) override;

private:
	GLuint	m_vao = 0;
	//GLuint	m_ebo = 0;c
	float* m_vertice = nullptr;
	unsigned int* m_indice = nullptr;
    
    berry::VertexBuffer*    m_vertexBuffer = nullptr;
	berry::IndexBuffer*		m_indexBuffer = nullptr;
};
