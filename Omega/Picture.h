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
		int GetHeight() const;
		int GetWidth() const;

	private:
		std::unique_ptr<PictureImplementation> mImplementation;

	};
}