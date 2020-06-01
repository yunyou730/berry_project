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


	class VertexArray;
	class IndexBuffer;
	class Shader;

	class Renderer
	{
	public:
		void SetClearColor(float r,float g,float b,float a);
		void Clear();
		void Draw(const VertexArray& va,const IndexBuffer& ib,const Shader& shader);
	};
}
