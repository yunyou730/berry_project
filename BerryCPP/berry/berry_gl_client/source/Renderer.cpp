#include "Renderer.h"
#include <stdio.h>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

using namespace berry;

void berry::GLCleanError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool berry::GLCheckError()
{
	bool bHasErr = false;
	while (GLenum err = glGetError())
	{
		printf("[OpenGL Error] 0x%x\n", err);
		bHasErr = true;
	}
	return !bHasErr;
}

void Renderer::SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r,g,b,a);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	va.Bind();
	ib.Bind();
	shader.Bind();

	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);

	va.Unbind();
	ib.Unbind();
	shader.Unbind();
}