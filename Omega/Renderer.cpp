#include "pch.h"
#include "Renderer.h"
#include "GLFWCode/OpenGLRenderer.h"



namespace omg {


	Renderer::Renderer()
	{
#ifdef OMEGA_MSCPP
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif OMEGA_APPLE
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif OMEGA_LINUX
		mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
	}

	void Renderer::Init()
	{
		mImplementation->Init();
	}

	void Renderer::Draw(int x, int y, Picture& pic)
	{
		mImplementation->Draw(x, y, pic);
	}

	void Renderer::Clear()
	{
		mImplementation->Clear();
	}
};

