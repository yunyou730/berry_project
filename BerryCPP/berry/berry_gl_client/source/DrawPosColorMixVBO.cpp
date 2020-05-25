#include "DrawPosColorMixVBO.h"
#include "GLUtil.h"

DrawPosColorMixVBO::~DrawPosColorMixVBO()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ebo);

	delete[] m_buffer;
	delete[] m_indice;
	
	m_buffer = nullptr;
	m_indice = nullptr;
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
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ebo);

	// VAO
	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, m_buffer, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, 0);

	GLCALL(glEnableVertexAttribArray(1));
	GLCALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, (void*)(sizeof(GL_FLOAT) * 2)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	// EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, m_indice, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void DrawPosColorMixVBO::Renderer()
{
	// pre draw
	glUseProgram(m_shaderID);
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);

	// do draw
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	// after draw
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
