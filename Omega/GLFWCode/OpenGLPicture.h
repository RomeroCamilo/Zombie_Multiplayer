#pragma once

#include "pch.h"
#include "PictureImplementation.h"

namespace omg 
{
	class OpenGLPicture : public PictureImplementation 
	{
	public:
		OpenGLPicture(const std::string& picturePath);

		virtual int GetHeight() const override;
		virtual int GetWidth() const override;

		~OpenGLPicture();

		void Bind() override;

	private:
		unsigned int mPictureProgram;
		int width;
		int height;

	};
}
