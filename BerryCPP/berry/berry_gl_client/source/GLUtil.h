#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>

#define GLCALL(x)	berry::GLCleanError();\
		(x);\
		assert(berry::GLCheckError());

namespace berry
{
	void GLCleanError();
	bool GLCheckError();
}
