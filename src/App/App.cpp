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
	, _inputManager(_mainWindow)
{}

/* ================================================================================ */

void App::run() {
	while (!_mainWindow.shouldClose()) {
	    _inputManager.update();          // 1. clear last frame's just-pressed state
        _windowManager.pollEvents();     // 2. GLFW fires callbacks → fills input state

		processInput();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		_mainWindow.swapBuffers();
	}
}

/* ================================================================================ */
/* ================================================================================ */
/* ================================================================================ */

void App::processInput() {
    if (_inputManager.wasJustPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(_mainWindow.get(), true);
}