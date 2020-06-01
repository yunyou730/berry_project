#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

/*
	1个 VAO  对应2个 VBO 的示例 

	顶点位置 vbo 
	顶点颜色 vbo 

	最终使用 ebo 绘制
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
	// 顶点位置信息
	float* m_vertice = nullptr;
	// 顶点 颜色 信息
	float* m_color = nullptr;
	// 顶点顺序 
	unsigned int* m_indice = nullptr;
};
