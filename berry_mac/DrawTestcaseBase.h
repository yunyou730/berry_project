#pragma once

class DrawTestcaseBase
{
public:
	virtual ~DrawTestcaseBase();

	virtual void Prepare() = 0;
	virtual void Renderer() = 0;
	void SetShader(unsigned int shaderID)
	{
		m_shaderID = shaderID;
	}

protected:
	unsigned int m_shaderID = 0;
};
