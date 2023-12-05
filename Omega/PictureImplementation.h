#pragma once

#include "pch.h"
#include "Utilities.h"

namespace omg 
{
	class PictureImplementation 
	{
	public:
		virtual void Bind() = 0;

		virtual ~PictureImplementation() {};
	};
}
