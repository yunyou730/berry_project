#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"

/*
	1个 VAO  对应2个 VBO 的示例 

	顶点位置 vbo 
	顶点颜色 vbo 

	最终使用 ebo 绘制
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
	// 顶点位置信息
	float* m_vertice = nullptr;
	// 顶点 颜色 信息
	float* m_color = nullptr;
	// 顶点顺序 
	unsigned int* m_indice = nullptr;
};
