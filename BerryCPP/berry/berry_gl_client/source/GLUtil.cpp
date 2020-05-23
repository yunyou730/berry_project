#include "GLUtil.h"
#include <stdio.h>

void berry::GLCleanError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool berry::GLCheckError()
{
	bool bHasErr = false;
	while (GLenum err = glGetError())
	{
		printf("[OpenGL Error] 0x%x\n",err);
		bHasErr = true;
	}
	return !bHasErr;
}
