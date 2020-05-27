#include "DrawPosColor.h"
#include "Renderer.h"

DrawPosColor::~DrawPosColor()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vboVertice);
	glDeleteBuffers(1, &m_vboColor);
	glDeleteBuffers(1, &m_ebo);

	delete[] m_vertice;
	delete[] m_color;
	delete[] m_indice;
	
	m_vertice = nullptr;
	m_color = nullptr;
	m_indice = nullptr;
}

void DrawPosColor::Prepare()
{
	m_vertice = new float[4 * 2];
	m_color = new float[4 * 4];
	m_indice = new unsigned int[6];

	int index = 0;
	m_vertice[index++] = -0.5; m_vertice[index++] = -0.5;
	m_vertice[index++] = -0.5; m_vertice[index++] =  0.5;
	m_vertice[index++] =  0.5; m_vertice[index++] =  0.5;
	m_vertice[index++] =  0.5; m_vertice[index++] = -0.5;

	index = 0;
	m_color[index++] = 1.0; m_color[index++] = 0.0; m_color[index++] = 0.0f; m_color[index++] = 1.0f;
	m_color[index++] = 0.0; m_color[index++] = 1.0; m_color[index++] = 0.0f; m_color[index++] = 1.0f;
	m_color[index++] = 0.0; m_color[index++] = 0.0; m_color[index++] = 1.0f; m_color[index++] = 1.0f;
	m_color[index++] = 1.0; m_color[index++] = 0.0; m_color[index++] = 1.0f; m_color[index++] = 1.0f;


	index = 0;
	m_indice[index++] = 0;
	m_indice[index++] = 1;
	m_indice[index++] = 2;
	m_indice[index++] = 0;
	m_indice[index++] = 3;
	m_indice[index++] = 2;

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vboVertice);
	glGenBuffers(1, &m_vboColor);
	glGenBuffers(1, &m_ebo);

	// VAO
	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vboVertice);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, m_vertice, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 2, 0);

	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_vboColor));
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 16, m_color, GL_STATIC_DRAW);
	GLCALL(glEnableVertexAttribArray(1));
	GLCALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 4, 0));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	// EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, m_indice, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void DrawPosColor::Renderer()
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
