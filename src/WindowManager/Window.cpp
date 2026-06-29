#include "Window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

/* ================================================================================ */

static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	(void)window;
	glViewport(0, 0, width, height);
}


/* ================================================================================ */

Window::Window(int width, int height, const std::string& title)
	: _handle(nullptr), _width(width), _height(height)
{

// ==========================================
// 3. CREATE THE WINDOW
// ==========================================
	// Actually requests the OS to spawn the window.
	_handle = glfwCreateWindow(_width, _height, title.c_str(), nullptr, nullptr);
	if (!_handle)
		throw std::runtime_error("Failed to create GLFW window: " + title);

// ==========================================
// 4. BIND OPENGL TO THE WINDOW
// ==========================================
	// Tells the computer: "All future OpenGL drawing commands should look at this specific window."
	glfwMakeContextCurrent(_handle);
	// Registers a custom callback function so if the user resizes the window, 
    // OpenGL will be notified immediately to adjust the image.
	glfwSetFramebufferSizeCallback(_handle, framebufferSizeCallback);

// ==========================================
// 6. INITIALIZE THE OPENGL VIEWPORT
// ==========================================
    // Tells OpenGL the coordinate mapping space for rendering inside the window.
    // (0, 0) is the bottom-left corner, mapping all the way to the width and height.
	glViewport(0, 0, _width, _height);
}


/* ================================================================================ */

Window::~Window() {
	glfwDestroyWindow(_handle);
}


/* ================================================================================ */

bool Window::shouldClose() const {
	return glfwWindowShouldClose(_handle);
}


/* ================================================================================ */

void Window::swapBuffers() const {
	glfwSwapBuffers(_handle);
}

