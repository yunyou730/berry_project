#include "DrawSimpleTexture.h"
#include "VertexBuffer.h"
#include "Renderer.h"
using namespace berry;


DrawSimpleTexture::~DrawSimpleTexture()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ebo);
    SAFE_DELETE(m_texture);
}

void DrawSimpleTexture::Prepare()
{
	float buffer[] = {
		-0.5,-0.5,
		-0.5, 0.5,
		 0.5, 0.5,
		 0.5,-0.5,
	};

	unsigned int indexBuffer[] = {
		0,1,2,
		3,0,2,
	};
	
	GLCALL(glGenVertexArrays(1, &m_vao));
	GLCALL(glGenBuffers(1, &m_vbo));
	GLCALL(glGenBuffers(1, &m_ebo));

	// VAO
	GLCALL(glBindVertexArray(m_vao));
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_vbo));
	GLCALL(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, buffer, GL_STATIC_DRAW));

	GLCALL(glEnableVertexAttribArray(0));
	GLCALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 2, 0));

	
	GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GLCALL(glBindVertexArray(0));

	// EBO
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo));
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indexBuffer, GL_STATIC_DRAW));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    
    // Texture
    m_texture = new Texture("res/wechat.png");
}

void DrawSimpleTexture::Renderer(berry::Renderer* renderer)
{
	GLCALL(glBindVertexArray(m_vao));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo));
	m_shader->Bind();
	GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0));
	GLCALL(glBindVertexArray(0));
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

}
