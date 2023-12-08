#pragma once

#include "Utilities.h"

namespace omg {
	class OMEGA_API KeyPressed 
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class OMEGA_API KeyReleased 
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class OMEGA_API WindowClosed {

	};

}
