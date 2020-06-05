#pragma once
#include "DrawTestcaseBase.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture2D.h"
using namespace berry;

class DrawSimpleTexture : public DrawTestcaseBase
{
public:
	virtual ~DrawSimpleTexture();

	void Prepare()  override;
	void Renderer(berry::Renderer* renderer) override;

private:
	GLuint		m_vao;
	GLuint		m_vbo;
	GLuint		m_ebo;
	Texture* m_texture = nullptr;
};

