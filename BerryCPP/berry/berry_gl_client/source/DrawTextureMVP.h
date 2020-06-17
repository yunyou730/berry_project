#pragma once

#include "DrawTestcaseBase.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture2D.h"

namespace berry
{
	class DrawTextureMVP : public DrawTestcaseBase
	{
	public:
		virtual ~DrawTextureMVP();
		virtual void Prepare() override;
		virtual void Renderer(berry::Renderer* renderer) override;

	private:
		VertexArray*		m_vao = nullptr;
		VertexBuffer*		m_vbo = nullptr;
        IndexBuffer*        m_ebo = nullptr;
        Texture*            m_texture = nullptr;
	};
}
