#include "DrawWithEBO.h"
#include "GLUtil.h"

DrawWithEBO::~DrawWithEBO()
{
	delete[] m_vertice;
	delete[] m_indice;
}

void DrawWithEBO::Prepare()
{
	// VAO,VBO
	m_vertice = new float[8];
	int index = 0;
	m_vertice[index++] =  0.0; m_vertice[index++] =  0.0;
	m_vertice[index++] =  0.0; m_vertice[index++] =  1.0;
	m_vertice[index++] =  1.0; m_vertice[index++] = -1.0;
	m_vertice[index++] =  1.0; m_vertice[index++] =  0.5;

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);

	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, m_vertice, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 2, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// EBO 
	m_indice = new unsigned int[6];

	index = 0;
	m_indice[index++] = 0;
	m_indice[index++] = 1;
	m_indice[index++] = 2;
	m_indice[index++] = 1;
	m_indice[index++] = 3;
	m_indice[index++] = 2;

	glGenBuffers(1, &m_ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, m_indice, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
}

void DrawWithEBO::Renderer()
{
	glUseProgram(m_shaderID);
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
