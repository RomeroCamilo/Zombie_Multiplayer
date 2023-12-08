#include "pch.h"
#include "Picture.h"
#include "GLFWCode/OpenGLPicture.h"

namespace omg 
{
	Picture::Picture(const std::string& picturePath)
	{
#ifdef OMEGA_MSCPP
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#elif OMEGA_APPLE
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#elif OMEGA_LINUX
		mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(picturePath) };
#endif
	}

	void Picture::Bind()
	{
		mImplementation->Bind();
	}

	int Picture::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int Picture::GetWidth() const
	{
		return mImplementation->GetWidth();
	}
}