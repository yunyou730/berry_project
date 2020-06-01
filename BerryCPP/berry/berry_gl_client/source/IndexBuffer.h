#pragma once
#include <GL/glew.h>

namespace berry
{
	class IndexBuffer
	{
	public:
		IndexBuffer(const unsigned int* data,unsigned int count);
        ~IndexBuffer();

		inline unsigned int GetCount() const { return m_count; }

		void Bind() const;
		void UnBind() const;
	private:
		unsigned int m_bufferID;
		int		     m_count;
	};
}
