#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>

#define GLCALL(x)	berry::GLCleanError();\
		(x);\
		assert(berry::GLCheckError());


#define SAFE_DELETE(x) if(x != nullptr){\
	delete (x);\
	x = nullptr;\
}

#define SAFE_DELETE_ARRAY(x) if(x != nullptr){\
	delete[] x;\
	x = nullptr;\
}

namespace berry
{
	void GLCleanError();
	bool GLCheckError();
}
