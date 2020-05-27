#include <GL/glew.h>

namespace berry
{
	class IndexBuffer
	{
	public:
		IndexBuffer(const void* data,unsigned int size);

		void Bind();
		void UnBind();
	private:
		unsigned int m_bufferID;
		int		m_count;
	};
}
