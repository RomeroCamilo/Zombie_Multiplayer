#pragma once

#include "Utilities.h"
#include "pch.h"
#include "WindowImplementation.h"
#include "Events.h"

namespace omg {

	class OMEGA_API GameWindow {

	public:
		GameWindow();
		void Create(const std::string& name, int width, int height);
		int GetHeight() const;
		int GetWidth() const;
		void SwapBuffers();
		void PollEvents();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc);
		void SetWindowCloseCallback(std::function<void()>& callbackFunc);



	private:
		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };
		
	};
}