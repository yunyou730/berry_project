#pragma once
#include <GLFW/glfw3.h>

namespace berry
{
	class Actor
	{
	public:
		Actor();
		virtual ~Actor();
		virtual void InitVertexBuffer() = 0;
		virtual void Draw() = 0;
	};
}
