#include "DrawWithEBO.h"
#include "GLUtil.h"

DrawWithEBO::~DrawWithEBO()
{
	delete[] m_vertice;
	delete[] m_indice;
}

void DrawWithEBO::Prepare()
{
	m_vertice = new float[8];
	m_indice = new unsigned int[6];

	int index = 0;
	m_vertice[index++] =  0.0; m_vertice[index++] =  0.0;
	m_vertice[index++] =  0.0; m_vertice[index++] =  1.0;
	m_vertice[index++] =  1.0; m_vertice[index++] = -1.0;
	m_vertice[index++] =  1.0; m_vertice[index++] =  0.5;

	index = 0;
	m_indice[index++] = 0;
	m_indice[index++] = 1;
	m_indice[index++] = 2;
	m_indice[index++] = 1;
	m_indice[index++] = 3;
	m_indice[index++] = 2;

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ebo);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, m_vertice, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, m_indice, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 2, 0);

	
	glEnableVertexAttribArray(0);


	glBindVertexArray(0);
}

void DrawWithEBO::Renderer()
{
	glBindVertexArray(m_vao);
	glUseProgram(m_shaderID);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawElements(GL_LINES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
