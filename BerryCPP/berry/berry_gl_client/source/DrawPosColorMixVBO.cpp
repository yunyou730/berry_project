#include "DrawPosColorMixVBO.h"
#include "Renderer.h"
#include "Shader.h"
using namespace berry;

DrawPosColorMixVBO::~DrawPosColorMixVBO()
{
	SAFE_DELETE(m_vertexArray);
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

	m_vertexArray = new berry::VertexArray();
	VertexBufferLayout layout;
	m_vertexBuffer = new berry::VertexBuffer(m_buffer, sizeof(float) * 24);

	// VAO
	layout.Push<float>(2);
	layout.Push<float>(4);
	m_vertexArray->AddBuffer(*m_vertexBuffer, layout);
	
	m_vertexBuffer->Unbind();
	m_vertexArray->Unbind();

	// EBO
	m_indexBuffer = new berry::IndexBuffer(m_indice, 6);
	m_indexBuffer->Unbind();
}

void DrawPosColorMixVBO::Renderer(berry::Renderer* renderer)
{
	renderer->Draw(*m_vertexArray, *m_indexBuffer, *m_shader);
}
