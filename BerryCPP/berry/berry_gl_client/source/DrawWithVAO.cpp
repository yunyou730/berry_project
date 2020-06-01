#include "DrawWithVAO.h"
using namespace berry;

DrawWithVAO::~DrawWithVAO()
{
	glDeleteVertexArrays(1, &m_vao);
	m_vao = 0;
    if(m_vertexBuffer != nullptr)
    {
        delete m_vertexBuffer;
        m_vertexBuffer = nullptr;
    }

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
    
    
    m_vertexBuffer = new VertexBuffer(m_vertice,12);
    
	
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
	m_shader->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	m_shader->Unbind();
	glBindVertexArray(0);
}
