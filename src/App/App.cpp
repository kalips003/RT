#include "App.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <iostream>

/* ================================================================================ */

static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	(void)window;
	glViewport(0, 0, width, height);
}

/* ================================================================================ */

App::App(int width, int height, const char* title)
	: _window(nullptr), _width(width), _height(height)
{
	if (!glfwInit())
		throw std::runtime_error("Failed to init GLFW");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	_window = glfwCreateWindow(_width, _height, title, nullptr, nullptr);
	if (!_window) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwTerminate();
		throw std::runtime_error("Failed to init GLAD");
	}

	glViewport(0, 0, _width, _height);
}

/* ================================================================================ */

App::~App() {
	glfwDestroyWindow(_window);
	glfwTerminate();
}

/* ================================================================================ */

void App::run() {
	while (!glfwWindowShouldClose(_window)) {
		processInput();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
}

/* ================================================================================ */

void App::processInput() {
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_window, true);
}