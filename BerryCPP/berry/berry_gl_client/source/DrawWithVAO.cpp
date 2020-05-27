#include "DrawWithVAO.h"
#include "Renderer.h"

DrawWithVAO::~DrawWithVAO()
{
	glDeleteVertexArrays(1, &m_vao);
	m_vao = 0;
	glDeleteBuffers(1, &m_vbo);
	m_vbo = 0;

	delete[] m_vertice;
	m_vertice = nullptr;
}

void DrawWithVAO::Prepare()
{


	
	m_vertice = new float[12];
	int index = 0;

	// make rectangle with 2 triangles 

	// lower left triangle
	m_vertice[index++] = -0.5f; m_vertice[index++] = -0.5f;
	m_vertice[index++] = -0.5f; m_vertice[index++] =  0.5f;
	m_vertice[index++] =  0.5f; m_vertice[index++] = -0.5f;
	
	// upper right triangle
	m_vertice[index++] = 0.5f; m_vertice[index++] = -0.5f;	// copy
	m_vertice[index++] = -0.5f; m_vertice[index++] = 0.5f;	// copy
	m_vertice[index++] =  0.5f; m_vertice[index++] = 0.5f;

	// VBO init data
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12, m_vertice, GL_STATIC_DRAW);
	
	// init VAO 
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	// let VAO hold VBO -> shader data map 
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 2, 0);
	glEnableVertexAttribArray(0);


	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);
	
}

void DrawWithVAO::Renderer()
{
	glBindVertexArray(m_vao);
	glUseProgram(m_shaderID);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glUseProgram(0);
	glBindVertexArray(0);
}
