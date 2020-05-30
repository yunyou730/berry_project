#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

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
	berry::VertexArray* m_vertexArray = nullptr;
	berry::VertexBuffer* m_vertexBuffer = nullptr;
	berry::IndexBuffer* m_indexBuffer = nullptr;

	// 顶点位置信息
	float* m_buffer = nullptr;
	// 顶点顺序 
	unsigned int* m_indice = nullptr;
};
