#pragma once

#include "pch.h"
#include "PictureImplementation.h"

namespace omg 
{
	class OpenGLPicture : public PictureImplementation 
	{
	public:
		OpenGLPicture(const std::string& picturePath);

		~OpenGLPicture();

		void Bind() override;

	private:
		unsigned int mPictureProgram;

	};
}
