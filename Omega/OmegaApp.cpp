#include "pch.h"
#include "OmegaApp.h"
#include "Utilities.h"

#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include "../stbi/stb_image.h"

#include "Shader.h"
#include "Picture.h"

namespace omg
{
	template <typename T>
	OmegaApp<T>::OmegaApp()
	{
	}

	template <typename T>
	void OmegaApp<T>::Init() {

		if (sInstance == nullptr)
			sInstance = new T;

	}

	template <typename T>
	void OmegaApp<T>::RunInterface() {
		sInstance->Run();

	}

	template <typename T>
	void OmegaApp<T>::Run()
	{

		mWindow.Create("Game CR", 1000, 800);


		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			OMG_ERROR("Failed to initialize GLAD");
			return;
		}


		float vertices[] = {
			100.f, 100.f, 0.0f, 0.0f,
			300.f, 100.f, 1.0f, 0.0f,
			100.f, 300.f, 0.0f, 1.0f,
			300.f, 300.f, 1.0f, 1.0f,
		};

		unsigned int indices[] = {
			0,1,2,
			1,2,3
		};

		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float))); // FIX
		glEnableVertexAttribArray(1);


		// SHADERS /////

		omg::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
		shader.SetUniform2Ints("ScreenSize", 1000, 800);

		// Textures / Picture /////

		omg::Picture pic{"../Assets/Pictures/test.png"};

	   // PROGRAM RUNNING ////

	   glEnable(GL_BLEND);
	   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		while (mShouldContinue) {

			OnUpdate();

			glClearColor(0.3f, 0.2f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();
			pic.Bind();

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			mWindow.SwapBuffers();
			mWindow.PollEvents();
			
		}
	}

	template <typename T>
	void OmegaApp<T>::OnUpdate() {

	}



	
}
