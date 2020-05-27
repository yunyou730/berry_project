#include <GL/glew.h>

namespace berry
{
	class IndexBuffer
	{
	public:
		IndexBuffer(const unsigned int* data,unsigned int size);
        ~IndexBuffer();

		void Bind();
		void UnBind();
	private:
		unsigned int m_bufferID;
		int		     m_count;
	};
}
