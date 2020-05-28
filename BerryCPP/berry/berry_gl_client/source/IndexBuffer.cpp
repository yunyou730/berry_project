#include "IndexBuffer.h"

berry::IndexBuffer::IndexBuffer(const unsigned int* data, int count)
{
    glGenBuffers(1,&m_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count * sizeof(unsigned int),data,GL_STATIC_DRAW);
}

berry::IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1,&m_bufferID);
}

void berry::IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_bufferID);
}

void berry::IndexBuffer::UnBind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
