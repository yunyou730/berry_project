#pragma once

#include <GL/glew.h>

namespace berry
{
	class VertexBuffer
	{
	public:
		VertexBuffer(const void* data,unsigned int size);
		~VertexBuffer();

		void Bind() const;
		void UnBind() const;

	private:
		unsigned int m_rendererID;
	};
}

