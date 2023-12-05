#pragma once

#include "pch.h"
#include "Utilities.h"
#include "PictureImplementation.h"

namespace omg 
{
	class OMEGA_API Picture {
	public:
		Picture(const std::string & picturePath);
		void Bind();

	private:
		std::unique_ptr<PictureImplementation> mImplementation;

	};
}