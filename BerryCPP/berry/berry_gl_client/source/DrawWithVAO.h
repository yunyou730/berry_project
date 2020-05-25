#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DrawTestcaseBase.h"

/*
	简单的 VAO 示例
	直接使用 VAO 对应一个 VBO 做绘制 
*/
class DrawWithVAO : public DrawTestcaseBase
{
public:
	~DrawWithVAO();

	virtual void Prepare() override;
	virtual void Renderer() override;

private:
	GLuint	m_vao = 0;
	GLuint	m_vbo = 0;
	float* m_vertice = nullptr;
};
