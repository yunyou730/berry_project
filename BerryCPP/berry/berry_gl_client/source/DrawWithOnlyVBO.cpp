#include "DrawWithOnlyVBO.h"

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

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, m_vertice, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 2, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void DrawWithOnlyVBO::Renderer()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glEnableVertexAttribArray(0);
	glUseProgram(m_shaderID);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
