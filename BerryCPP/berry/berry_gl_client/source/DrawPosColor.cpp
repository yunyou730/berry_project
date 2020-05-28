#include "DrawPosColor.h"
#include "Renderer.h"
using namespace berry;

DrawPosColor::~DrawPosColor()
{
	glDeleteVertexArrays(1, &m_vao);

	SAFE_DELETE(m_posBuffer);
	SAFE_DELETE(m_colorBuffer);
	SAFE_DELETE(m_indexBuffer);

	SAFE_DELETE_ARRAY(m_vertice);
	SAFE_DELETE_ARRAY(m_color);
	SAFE_DELETE_ARRAY(m_indice);
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
	m_posBuffer = new VertexBuffer(m_vertice, sizeof(float) * 8);
	m_colorBuffer = new VertexBuffer(m_color, sizeof(float) * 16);
	m_indexBuffer = new IndexBuffer(m_indice, 6);
	m_indexBuffer->UnBind();

	// VAO
	glBindVertexArray(m_vao);
	
	m_posBuffer->Bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 2, 0);

	m_colorBuffer->Bind();
	GLCALL(glEnableVertexAttribArray(1));
	GLCALL(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 4, 0));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void DrawPosColor::Renderer()
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
