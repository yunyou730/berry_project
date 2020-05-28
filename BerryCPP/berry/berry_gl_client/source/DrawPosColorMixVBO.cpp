#include "DrawPosColorMixVBO.h"
#include "Renderer.h"
using namespace berry;

DrawPosColorMixVBO::~DrawPosColorMixVBO()
{
	glDeleteVertexArrays(1, &m_vao);

	SAFE_DELETE(m_vertexBuffer);
	SAFE_DELETE(m_indexBuffer);
	
	SAFE_DELETE_ARRAY(m_buffer);
	SAFE_DELETE_ARRAY(m_indice);
}

void DrawPosColorMixVBO::Prepare()
{
	m_buffer = new float[4 * 6];
	m_indice = new unsigned int[6];

	int index = 0;
	// v1
	m_buffer[index++] = -0.5; m_buffer[index++] = -0.5;		// pos
	m_buffer[index++] = 1.0; m_buffer[index++] = 1.0; m_buffer[index++] = 0.0f; m_buffer[index++] = 1.0f;	// color
	// v2
	m_buffer[index++] = -0.5; m_buffer[index++] =  0.5;
	m_buffer[index++] = 0.0; m_buffer[index++] = 1.0; m_buffer[index++] = 1.0f; m_buffer[index++] = 1.0f;
	// v3
	m_buffer[index++] =  0.5; m_buffer[index++] =  0.5;
	m_buffer[index++] = 1.0; m_buffer[index++] = 0.0; m_buffer[index++] = 1.0f; m_buffer[index++] = 1.0f;
	// v4
	m_buffer[index++] =  0.5; m_buffer[index++] = -0.5;
	m_buffer[index++] = 1.0; m_buffer[index++] = 0.5; m_buffer[index++] = 1.0f; m_buffer[index++] = 1.0f;


	index = 0;
	m_indice[index++] = 0;
	m_indice[index++] = 1;
	m_indice[index++] = 2;
	m_indice[index++] = 0;
	m_indice[index++] = 3;
	m_indice[index++] = 2;

	glGenVertexArrays(1, &m_vao);
	m_vertexBuffer = new berry::VertexBuffer(m_buffer, sizeof(float) * 24);

	// VAO
	glBindVertexArray(m_vao);

	m_vertexBuffer->Bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, 0);
	GLCALL(glEnableVertexAttribArray(1));
	GLCALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, (void*)(sizeof(GL_FLOAT) * 2)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// EBO
	m_indexBuffer = new berry::IndexBuffer(m_indice, 6);
	m_indexBuffer->UnBind();
}

void DrawPosColorMixVBO::Renderer()
{
	// pre draw
	glUseProgram(m_shaderID);
	glBindVertexArray(m_vao);
	m_indexBuffer->Bind();

	// do draw
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	// after draw
	m_indexBuffer->UnBind();
	glBindVertexArray(0);
}
