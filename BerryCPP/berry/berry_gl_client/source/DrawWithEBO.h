#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawTestcaseBase.h"

/*
	简单的EBO 示例 

	使用一个 VAO 对应一个 顶点位置 VBO  
	生成 EBO 进行 绘制 
*/
class DrawWithEBO : public DrawTestcaseBase
{
public:
	~DrawWithEBO();

	virtual void Prepare() override;
	virtual void Renderer() override;

private:
	GLuint	m_vao = 0;
	GLuint	m_vbo = 0;
	GLuint	m_ebo = 0;
	float* m_vertice = nullptr;
	unsigned int* m_indice = nullptr;
};
