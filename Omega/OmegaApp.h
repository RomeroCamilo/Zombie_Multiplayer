#pragma once

#include "Utilities.h"

#include "GameWindow.h"

namespace omg
{
	template<typename T>
	class OmegaApp { 

	public:
		static void Init();
		static void RunInterface();

		
		void Run();
		void virtual OnUpdate();

		friend typename T;

	private:
		OmegaApp();

		inline static OmegaApp* sInstance{ nullptr };

		GameWindow mWindow;

		bool mShouldContinue{ true };

	};
};

#include "OmegaApp.cpp"


