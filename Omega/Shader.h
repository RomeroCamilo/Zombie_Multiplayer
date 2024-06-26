#pragma once

#include "Utilities.h"
#include "pch.h"
#include"ShaderImplementation.h"

/* this is the user level class of shader */
namespace omg {
	class OMEGA_API Shader
	{
	public:
		Shader(const std::string& vertexSFile, const std::string& fragmentSFile);
		void Bind();
		void SetUniform2Ints(const std::string& uniformName, int val1, int val2);
		void SetUniform2Ints(std::string&& uniformName, int val1, int val2);

	private:
		std::unique_ptr<ShaderImplementation> mImplementation;

	};
}
