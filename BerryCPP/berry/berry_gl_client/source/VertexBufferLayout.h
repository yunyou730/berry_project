#pragma once
#include <GL/glew.h>
#include <vector>
#include <cassert>
#include "Renderer.h"

namespace berry
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char bNomalized;

		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT:
				return sizeof(GLfloat);
			case GL_UNSIGNED_INT:
				return sizeof(GLuint);
			case GL_UNSIGNED_BYTE:
				return sizeof(GLbyte);
			}
			assert(false);
			return 0;
		}
	};

	class VertexBufferLayout
	{
	public:

		VertexBufferLayout() :m_stride(0)
		{
		
		}

		template<typename T>
		void Push(unsigned int count)
		{
			assert(false);
		}

		template<>
		void Push<float>(unsigned int count)
		{
			m_elements.push_back({GL_FLOAT,count,GL_FALSE });
			m_stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
		}

		template<>
		void Push<unsigned int>(unsigned int count)
		{
			m_elements.push_back({ GL_UNSIGNED_INT,count,GL_FALSE });
			m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
		}

		template<>
		void Push<unsigned char>(unsigned int count)
		{
			m_elements.push_back({GL_UNSIGNED_BYTE,count,GL_TRUE});
			m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
		}

		inline unsigned int GetStride() const 
		{
			return m_stride;
		}

		inline const std::vector<VertexBufferElement>& GetElements() const
		{
			return m_elements;
		}

	private:
		std::vector<VertexBufferElement>	m_elements;
		unsigned int						m_stride;
	};
}
