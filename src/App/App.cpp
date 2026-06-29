#include "App.hpp"
#include "Log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <iostream>

/* ================================================================================ */

App::App(int width, int height, const char* title)
    : _windowManager()
    , _mainWindow(_windowManager.createWindow(width, height, title))
{}

/* ================================================================================ */

void App::run() {
	while (!_mainWindow.shouldClose()) {
		processInput();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		_mainWindow.swapBuffers();
		_windowManager.pollEvents();
	}
}

/* ================================================================================ */
/* ================================================================================ */
/* ================================================================================ */

void App::processInput() {
	if (glfwGetKey(_mainWindow.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_mainWindow.get(), true);
}