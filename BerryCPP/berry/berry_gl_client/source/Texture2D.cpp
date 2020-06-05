#include "Texture2D.h"
#include "stb_image.h"

berry::Texture::Texture(const std::string& path)
	:m_filePath(path)
	, m_localBuffer(nullptr)
	, m_width(0)
	, m_height(0)
	, m_bpp(0)
{
	GLCALL(glGenTextures(1,&m_textureID));
	GLCALL(glBindTexture(GL_TEXTURE_2D,m_textureID));

	//stbi_set_flip_vertically_on_load(1);
	m_localBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_bpp, 4);// 4 means RGBA

	// test don't set ...
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP));

	GLCALL(glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,m_width,m_height,0,GL_RGBA,GL_UNSIGNED_BYTE,m_localBuffer));
	glBindTexture(GL_TEXTURE_2D, 0);

	if (m_localBuffer)
	{
		stbi_image_free(m_localBuffer);
		m_localBuffer = nullptr;
	}
}

berry::Texture::~Texture()
{
	glDeleteTextures(1, &m_textureID);
}

void berry::Texture::Bind(unsigned int slot /*= 0*/) const
{
	GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
	GLCALL(glBindTexture(GL_TEXTURE_2D, m_textureID));
}

void berry::Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
