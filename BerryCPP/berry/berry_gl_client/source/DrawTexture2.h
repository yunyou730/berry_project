#pragma once

#include "DrawTestcaseBase.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

namespace berry
{
	class DrawTexture2 : public DrawTestcaseBase
	{
	public:
		virtual ~DrawTexture2();
		virtual void Prepare() override;
		virtual void Renderer(berry::Renderer* renderer) override;

	private:
		VertexArray*		m_vao = nullptr;
		VertexBuffer*		m_vbo = nullptr;
	};
}
