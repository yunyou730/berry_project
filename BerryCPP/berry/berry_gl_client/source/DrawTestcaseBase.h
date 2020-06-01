#pragma once

namespace berry
{
	class Shader;
	class Renderer;
	class DrawTestcaseBase
	{
	public:
		virtual ~DrawTestcaseBase();

		virtual void Prepare() = 0;
		virtual void Renderer(berry::Renderer* renderer) = 0;
		void SetShader(berry::Shader* shader)
		{
			m_shader = shader;
		}

	protected:
		berry::Shader*	m_shader = nullptr;
	};

}
