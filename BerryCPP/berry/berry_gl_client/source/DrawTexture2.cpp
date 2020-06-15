#include "DrawTexture2.h"

using namespace berry;

DrawTexture2::~DrawTexture2()
{
	SAFE_DELETE(m_vao); 
	SAFE_DELETE(m_vbo);
}

void DrawTexture2::Prepare()
{
	m_vao = new VertexArray();

	float arr[] = {
		// lower left
		-0.5,-0.5,	// pos
		 0.0, 0.0,	// uv

		// upper left
		-0.5, 0.5,	// pos
		 0.0, 1.0,	// uv

		 // upper right 
		 0.5, 0.5,	// pos
		 1.0, 1.0,	// uv

		 // lower right 
		 0.5,-0.5,	// pos
		 1.0, 0.0,	// uv
	};
	int count = sizeof(arr) / sizeof(float);
	m_vbo = new VertexBuffer(arr,count);

	VertexBufferLayout layout;

	//throw std::logic_error("The method or operation is not implemented.");
}

void DrawTexture2::Renderer(berry::Renderer* renderer)
{
	//throw std::logic_error("The method or operation is not implemented.");
}

