#pragma once
#include <GL/glew.h>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace berry
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
				
		void AddBuffer(const VertexBuffer& vb,const VertexBufferLayout& layout);

		void Bind() const;
		void Unbind() const;

	private:
		GLuint	m_vao = 0;
	};
}
