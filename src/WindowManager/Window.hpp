#pragma once
#include "Log.hpp"
#include <string>

struct GLFWwindow;

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    Window(const Window&)            = delete;
    Window& operator=(const Window&) = delete;

// 
    bool        shouldClose() const;
    void        swapBuffers() const;

//	GETTERS
    GLFWwindow* get() const { return _handle; }
    int         width()  const { return _width; }
    int         height() const { return _height; }

private:
    GLFWwindow* _handle;
    int         _width;
    int         _height;
};