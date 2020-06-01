#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

/*
	1�� VAO  ��Ӧ2�� VBO ��ʾ�� 

	����λ�� vbo 
	������ɫ vbo 

	����ʹ�� ebo ����
*/
class DrawPosColor : public berry::DrawTestcaseBase
{
public:
	~DrawPosColor();

	virtual void Prepare() override;
	virtual void Renderer(berry::Renderer* renderer) override;

private:
	GLuint	m_vao = 0;

	berry::VertexBuffer* m_posBuffer = nullptr;
	berry::VertexBuffer* m_colorBuffer = nullptr;
	berry::IndexBuffer*  m_indexBuffer = nullptr;

	//const static int VERTICE_CNT = 4;
	// ����λ����Ϣ
	float* m_vertice = nullptr;
	// ���� ��ɫ ��Ϣ
	float* m_color = nullptr;
	// ����˳�� 
	unsigned int* m_indice = nullptr;
};
