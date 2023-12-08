#include "pch.h"
#include "OpenGLPicture.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../stbi/stb_image.h"


namespace omg 
{
	OpenGLPicture::OpenGLPicture(const std::string& picturePath)
	{

		glGenTextures(1, &mPictureProgram);

		Bind();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(picturePath.c_str(), &width, &height, &nrChannels, 0);
		std::cout << "Height: " << height << " ";

		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			OMG_ERROR("Failed to load a picture from the file!!!");
		};
		stbi_image_free(data);
	}

	int OpenGLPicture::GetHeight() const
	{
		//std::cout << "Height: " << height <<" ";

		return height;
	}

	int OpenGLPicture::GetWidth() const
	{
		//std::cout << "width: " << width << " ";

		return width;
	}

	OpenGLPicture::~OpenGLPicture()
	{
		glDeleteTextures(1, &mPictureProgram);
	}

	void OpenGLPicture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mPictureProgram);

	}
}