#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DrawTestcaseBase.h"

/*
	��ʹ�� VAO ���Ƶ�ʾ��  
	�� OpenGL Core Profile �»�����û������ VAO ���� 
*/
class DrawWithOnlyVBO : public DrawTestcaseBase
{
public:
	~DrawWithOnlyVBO();

	virtual void Prepare() override;
	virtual void Renderer() override;

private:
	GLuint	m_vbo = 0;
	float* m_vertice = nullptr;
};
