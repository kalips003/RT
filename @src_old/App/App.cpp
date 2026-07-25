#include "App.hpp"
#include "Log.hpp"
#include "Parser.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// #include <stdexcept>
// #include <iostream>


// pixel (0,0) top-left → NDC (-1,1) top-left
static float toNdcX(double px, int width) {
    return  (float)(px / width)  * 2.0f - 1.0f;
}
static float toNdcY(double py, int height) {
    return -(float)(py / height) * 2.0f + 1.0f;
}

/* ================================================================================ */

App::App(int width, int height, const char* title)
    : _windowManager()
    , _mainWindow(_windowManager.createWindow(width, height, title))
	, _inputManager(_mainWindow)
	, _renderer()
{
    // triangle
    _renderer.addMesh("triangle", {
         0.0f,  0.5f, 0.0f,   // top
        -0.5f, -0.5f, 0.0f,   // bottom left
         0.5f, -0.5f, 0.0f,   // bottom right
    });

    // quad (two triangles)
    _renderer.addMesh("quad", {
        -0.5f,  0.5f, 0.0f,   // top left
        -0.5f, -0.5f, 0.0f,   // bottom left
         0.5f, -0.5f, 0.0f,   // bottom right

        -0.5f,  0.5f, 0.0f,   // top left
         0.5f, -0.5f, 0.0f,   // bottom right
         0.5f,  0.5f, 0.0f,   // top right
    });
}

/* ================================================================================ */

void App::run() {
	while (!_mainWindow.shouldClose()) {
	    _inputManager.update();          // 1. clear last frame's just-pressed state
        _windowManager.pollEvents();     // 2. GLFW fires callbacks → fills input state

		processInput();
        update();

        _renderer.clear();

        if (_drawTriangle)
            _renderer.draw("triangle", 1.0f, 0.5f, 0.2f);  // orange, center

        if (_drawQuad)
            _renderer.draw("quad", 0.2f, 0.8f, 0.2f);      // green, center

        if (_drawBlue)
            _renderer.draw("triangle", 0.2f, 0.4f, 1.0f,   // blue, at click pos
                           _blueX, _blueY);

		_mainWindow.swapBuffers();
	}
}

/* ================================================================================ */
/* ================================================================================ */
/* ================================================================================ */

void App::processInput() {
    if (_inputManager.wasJustPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(_mainWindow.get(), true);

    if (_inputManager.wasJustPressed(GLFW_KEY_1))
        _drawTriangle = !_drawTriangle;   // toggle

    if (_inputManager.wasJustPressed(GLFW_KEY_2))
        _drawQuad = !_drawQuad;           // toggle

    // right click → toggle blue triangle at mouse position
    if (_inputManager.wasMouseJustPressed(GLFW_MOUSE_BUTTON_RIGHT)) {
        MouseState mouse = _inputManager.getMouse();
        _blueX    = toNdcX(mouse.x, _mainWindow.width());
        _blueY    = toNdcY(mouse.y, _mainWindow.height());
        _drawBlue = !_drawBlue;
    }

    // left click → toggle quad
    if (_inputManager.wasMouseJustPressed(GLFW_MOUSE_BUTTON_LEFT))
        _drawQuad = !_drawQuad;
		
}

void App::update() {
    // empty for now — will hold movement, physics, scene updates
}

/* ================================================================================ */

void App::openRTFile(const std::string& file_name) {
    Scene newScene = Parser::parseRTFile(file_name, _resourceManager);
    _sceneManager.addScene(std::move(newScene));
}
