#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DrawTestcaseBase.h"

/*
	不使用 VAO 绘制的示例  
	在 OpenGL Core Profile 下会由于没有生成 VAO 报错 
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
