#pragma once

#include "Utilities.h"

namespace omg
{
	template<typename T>
	class OMEGA_API OmegaApp { /* beaver app class is visible to user of framework */

	public:
		static void Init();
		static void RunInterface();

		
		void Run();
		void virtual OnUpdate();

		friend typename T;

	private:
		OmegaApp();

		inline static OmegaApp* sInstance{ nullptr };

		bool mShouldContinue{ true };

	};
};

#include "OmegaApp.cpp"


