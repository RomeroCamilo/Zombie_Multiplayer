#include "pch.h"
#include "OmegaApp.h"
#include "Utilities.h"
#include "Shader.h"
#include "Picture.h"
#include "Renderer.h"


namespace omg
{
	template <typename T>
	OmegaApp<T>::OmegaApp()
	{
		mWindow.Create("Game_CR", 1100, 800);

		mRenderer.Init();

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
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

	template <typename T>
	void OmegaApp<T>::Run()
	{

		omg::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };

		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue) {

			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template <typename T>
	void OmegaApp<T>::OnUpdate() {

	}

	template<typename T>
	void OmegaApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void OmegaApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void OmegaApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mWindow.SetWindowCloseCallback(callbackFunc);
	}

	template<typename T>
	void OmegaApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}

	template <typename T>
	void OmegaApp<T>::Draw(int x, int y, Picture& pic) {
		sInstance->mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void OmegaApp<T>::Draw(Unit& item)
	{
		sInstance->mRenderer.Draw(item.mXPosition, item.mYPosition, item.mImage);
	}

	
}
