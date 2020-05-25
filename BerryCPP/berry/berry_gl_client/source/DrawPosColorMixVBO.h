#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"

/*
	1个VAO 对应 1个混合数据 VBO 的示例 
	VBO 里混合包含 顶点位置,顶点颜色信息 	
	最终使用 ebo 绘制
*/
class DrawPosColorMixVBO : public DrawTestcaseBase
{
public:
	~DrawPosColorMixVBO();

	virtual void Prepare() override;
	virtual void Renderer() override;

private:
	GLuint	m_vao = 0;
	GLuint	m_vbo = 0;
	GLuint	m_ebo = 0;

	// 顶点位置信息
	float* m_buffer = nullptr;
	// 顶点顺序 
	unsigned int* m_indice = nullptr;
};
