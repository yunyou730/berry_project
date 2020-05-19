#pragma once
#include "Actor.h"

namespace berry
{
	class Triangle : public Actor
	{
	public:
		virtual void InitVertexBuffer() override;
		virtual void Draw() override;

	private:
		GLuint	m_vertexBuffer = 0;
	};
}
