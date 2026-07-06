#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <array>
#include "Log.hpp"

struct MouseState {
    double x, y;
    double deltaX, deltaY;
};

class Window;

class InputManager {
public:
    InputManager(Window& window);
    ~InputManager() = default;

    InputManager(const InputManager&)            = delete;
    InputManager& operator=(const InputManager&) = delete;

    void    update();   // call once per frame, before pollEvents

    // keyboard
    bool    isKeyDown(int key)       const;
    bool    wasJustPressed(int key)  const;
    bool    wasJustReleased(int key) const;

    // mouse buttons
    bool    isMouseDown(int button)         const;
    bool    wasMouseJustPressed(int button) const;

    // mouse position
    MouseState  getMouse() const { return _mouse; }

private:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursorCallback(GLFWwindow* window, double x, double y);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

    static constexpr int KEY_COUNT = GLFW_KEY_LAST + 1;
    static constexpr int MOUSE_COUNT = GLFW_MOUSE_BUTTON_LAST + 1;

    std::array<bool, KEY_COUNT> _keyDown{};
    std::array<bool, KEY_COUNT> _keyJustPressed{};
    std::array<bool, KEY_COUNT> _keyJustReleased{};

    std::array<bool, MOUSE_COUNT> _mouseDown{};
    std::array<bool, MOUSE_COUNT> _mouseJustPressed{};
    
    MouseState  _mouse{};
    double      _lastMouseX{};
    double      _lastMouseY{};

    Window&     _window;
};