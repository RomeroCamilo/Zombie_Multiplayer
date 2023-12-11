#pragma once

#include "Utilities.h"
#include "Renderer.h"
#include "GameWindow.h"
#include "Picture.h"
#include "Events.h"
#include "Unit.h"

namespace omg
{

	constexpr int FPS{ 60 };
	template<typename T>
	class OmegaApp { 

	public:
		static void Init();
		static void RunInterface();

		
		void Run();
		void virtual OnUpdate();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased &) > callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

		void DefaultWindowCloseHandler();

		static void Draw(int x, int y, Picture& pic);
		static void Draw(Unit& item);

		friend typename T;

	private:
		OmegaApp();

		inline static OmegaApp* sInstance{ nullptr };

		GameWindow mWindow;

		Renderer mRenderer;

		bool mShouldContinue{ true };

		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;

	};
};

#include "OmegaApp.cpp"


