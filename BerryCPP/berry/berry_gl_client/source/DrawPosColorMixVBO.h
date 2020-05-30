#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

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
	berry::VertexArray* m_vertexArray = nullptr;
	berry::VertexBuffer* m_vertexBuffer = nullptr;
	berry::IndexBuffer* m_indexBuffer = nullptr;

	// ����λ����Ϣ
	float* m_buffer = nullptr;
	// ����˳�� 
	unsigned int* m_indice = nullptr;
};
