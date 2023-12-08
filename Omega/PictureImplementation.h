#pragma once

#include "pch.h"
#include "Utilities.h"

namespace omg 
{
	class PictureImplementation 
	{
	public:
		virtual void Bind() = 0;

		virtual int GetHeight() const = 0;
		virtual int GetWidth() const = 0;

		virtual ~PictureImplementation() {};
	};
}
