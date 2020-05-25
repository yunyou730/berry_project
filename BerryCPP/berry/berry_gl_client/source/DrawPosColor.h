#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"

/*
	1�� VAO  ��Ӧ2�� VBO ��ʾ�� 

	����λ�� vbo 
	������ɫ vbo 

	����ʹ�� ebo ����
*/
class DrawPosColor : public DrawTestcaseBase
{
public:
	~DrawPosColor();

	virtual void Prepare() override;
	virtual void Renderer() override;

private:
	GLuint	m_vao = 0;
	GLuint	m_vboVertice = 0;
	GLuint	m_vboColor = 0;
	GLuint	m_ebo = 0;


	//const static int VERTICE_CNT = 4;
	// ����λ����Ϣ
	float* m_vertice = nullptr;
	// ���� ��ɫ ��Ϣ
	float* m_color = nullptr;
	// ����˳�� 
	unsigned int* m_indice = nullptr;
};
