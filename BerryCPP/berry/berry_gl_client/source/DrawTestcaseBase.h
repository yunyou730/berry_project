#pragma once
#include "Shader.h"

class DrawTestcaseBase
{
public:
	virtual ~DrawTestcaseBase();

	virtual void Prepare() = 0;
	virtual void Renderer() = 0;
	void SetShader(berry::Shader* shader)
	{
		m_shader = shader;
	}

protected:
	berry::Shader*	m_shader = nullptr;
};
