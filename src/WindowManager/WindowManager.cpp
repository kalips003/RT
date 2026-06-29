#include "WindowManager.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

/* ================================================================================ */

WindowManager::WindowManager() {

// ==========================================
// 1. INITIALIZE GLFW (The Window Manager)
// ==========================================
	if (!glfwInit())
		throw std::runtime_error("Failed to init GLFW");
	LOG_HERE(RED "WindowManager 1" RESET);

// ==========================================
// 2. CONFIGURE OPENGL SETTINGS (Window Hints)
// ==========================================
	// Request OpenGL version 4.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	// Use the "Core" profile (removes outdated 90s OpenGL functions)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// Apple/macOS requires an extra setting to allow forward compatibility with newer specs
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	LOG_HERE(RED "WindowManager 2" RESET);

}

/* ================================================================================ */

WindowManager::~WindowManager() {
	_windows.clear();   // destroy all Window objects before glfwTerminate
	glfwTerminate();
}

/* ================================================================================ */
/* ================================================================================ */
/* ================================================================================ */

Window& WindowManager::createWindow(int width, int height, const std::string& title) {
	LOG_HERE(RED "WindowManager 3.0" RESET);
	_windows.push_back(std::make_unique<Window>(width, height, title));
	LOG_HERE(RED "WindowManager 3.1" RESET);

// If first window — load GLAD now:
// ==========================================
// 5. INITIALIZE GLAD (The Function Loader)
// ==========================================
    // Because OpenGL functions are built into your GPU drivers, GLAD needs to dynamically look up where those functions live in your system's memory.
    // 'glfwGetProcAddress' passes GLFW's internal system locator tool over to GLAD.
	if (_windows.size() == 1) {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			throw std::runtime_error("Failed to init GLAD");
	}
	LOG_HERE(RED "WindowManager 4" RESET);

	return *_windows.back();
}

/* ================================================================================ */

Window& WindowManager::getMainWindow() {
	if (_windows.empty())
		throw std::runtime_error("No windows created");
	return *_windows.front();
}

/* ================================================================================ */

void WindowManager::pollEvents() const {
	glfwPollEvents();
}