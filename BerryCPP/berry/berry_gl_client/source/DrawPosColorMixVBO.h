#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

/*
	1��VAO ��Ӧ 1��������� VBO ��ʾ�� 
	VBO ���ϰ��� ����λ��,������ɫ��Ϣ 	
	����ʹ�� ebo ����
*/
class DrawPosColorMixVBO : public DrawTestcaseBase
{
public:
	~DrawPosColorMixVBO();

	virtual void Prepare() override;
	virtual void Renderer() override;

private:
	GLuint	m_vao = 0;

	berry::VertexBuffer* m_vertexBuffer = nullptr;
	berry::IndexBuffer* m_indexBuffer = nullptr;

	// ����λ����Ϣ
	float* m_buffer = nullptr;
	// ����˳�� 
	unsigned int* m_indice = nullptr;
};
