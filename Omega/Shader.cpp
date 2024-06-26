#include "pch.h"
#include "Shader.h"
#include "GLFWCode/OpenGLShader.h"

namespace omg {

	Shader::Shader(const std::string& vertexSFile, const std::string& fragmentSFile)
	{

#ifdef OMEGA_MSCPP
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#elif OMEGA_APPLE
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#elif OMEGA_LINUX
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, fragmentSFile) };
#endif
	}

	void Shader::Bind()
	{
		mImplementation->Bind();
	}
	void Shader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(uniformName, val1, val2);
	}
	void Shader::SetUniform2Ints(std::string&& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(move(uniformName), val1, val2);
	}
}