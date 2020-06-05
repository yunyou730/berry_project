#pragma once

#include "gl/glew.h"
#include <string>

#include "Renderer.h"

namespace berry
{
	class Texture
	{
	public:
		Texture(const std::string& path);
		~Texture();

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;

		inline int GetWidth() const { return m_width; }
		inline int GetHeight() const { return m_height; }

	private:
		unsigned int m_textureID = 0;
		std::string		m_filePath;
		unsigned char* m_localBuffer = nullptr;
		int m_width, m_height, m_bpp;
	};


}
