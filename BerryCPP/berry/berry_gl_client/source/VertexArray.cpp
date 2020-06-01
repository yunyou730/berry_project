#include "VertexArray.h"
#include "Renderer.h"

using namespace berry;

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_vao);
	
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_vao);
}

void VertexArray::AddBuffer(const VertexBuffer& vb,const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	long long offset = 0;
	for(int i = 0;i < elements.size();i++)
	{
		const VertexBufferElement& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, 
			element.type, 
			element.bNomalized,
			layout.GetStride(), (void*)offset);
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_vao);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}
