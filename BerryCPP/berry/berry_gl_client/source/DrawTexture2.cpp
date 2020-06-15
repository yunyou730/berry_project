#include "DrawTexture2.h"

using namespace berry;

DrawTexture2::~DrawTexture2()
{
	SAFE_DELETE(m_vao); 
	SAFE_DELETE(m_vbo);
    SAFE_DELETE(m_ebo);
    SAFE_DELETE(m_texture);
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
	m_vbo = new VertexBuffer(arr,sizeof(arr));

	VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);
    m_vao->AddBuffer(*m_vbo,layout);
    
    
    // index buffer
    unsigned int index[] = {
        0,1,2,
        0,2,3,
    };
    int count = sizeof(index) / sizeof(unsigned int);
    m_ebo = new IndexBuffer(index,count);
    
    // texture
    m_texture = new Texture("res/timeline.png");
}

void DrawTexture2::Renderer(berry::Renderer* renderer)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    m_texture->Bind();
    renderer->Draw(*m_vao, *m_ebo, *m_shader);
}

