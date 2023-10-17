#include "pch.h"
#include "OmegaApp.h"

namespace omg 
{
	template <typename T>
	OmegaApp<T>::OmegaApp()
	{
	}

	template <typename T>
	void OmegaApp<T>::Run()
	{

	   mWindow.Create("Game CR", 1000, 800);

		while (mShouldContinue) {
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
			
		}
	}

	template <typename T>
	void OmegaApp<T>::OnUpdate() {

	}

	template <typename T>
	void OmegaApp<T>::Init() {

		if (sInstance == nullptr)
			sInstance = new T;

	}

	template <typename T>
	void OmegaApp<T>::RunInterface() {
		sInstance->Run();
	}
}
