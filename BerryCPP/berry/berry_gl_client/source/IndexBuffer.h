#pragma once
#include <GL/glew.h>

namespace berry
{
	class IndexBuffer
	{
	public:
		IndexBuffer(const unsigned int* data,int count);
        ~IndexBuffer();

		void Bind();
		void UnBind();
	private:
		unsigned int m_bufferID;
		int		     m_count;
	};
}
