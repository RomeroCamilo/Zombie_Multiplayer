#pragma once

#include "Utilities.h"
#include "pch.h"
#include "WindowImplementation.h"

namespace omg {

	class OMEGA_API GameWindow {

	public:
		GameWindow();
		void Create(const std::string& name, int width, int height);
		int GetHeight() const;
		int GetWidth() const;
		void SwapBuffers();
		void PollEvents();


	private:
		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };
		
	};
}