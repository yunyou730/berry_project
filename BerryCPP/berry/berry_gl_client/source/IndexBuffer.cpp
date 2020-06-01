#include "IndexBuffer.h"
#include <cassert>

berry::IndexBuffer::IndexBuffer(const unsigned int* data,unsigned int count)
    :m_count(count)
{
    assert(sizeof(unsigned int) == sizeof(GLuint));
    glGenBuffers(1,&m_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_count * sizeof(unsigned int),data,GL_STATIC_DRAW);
}

berry::IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1,&m_bufferID);
}

void berry::IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_bufferID);
}

void berry::IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
