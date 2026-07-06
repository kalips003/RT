#include "InputManager.hpp"
#include "Window.hpp"

#include <stdexcept>

InputManager::InputManager(Window& window)
    : _window(window)
{
    GLFWwindow* handle = _window.get();

    // store `this` in the window so static callbacks can retrieve it
    glfwSetWindowUserPointer(handle, this);

    glfwSetKeyCallback(handle, keyCallback);
    glfwSetCursorPosCallback(handle, cursorCallback);

    // seed mouse position so first delta isn't a huge jump
    glfwGetCursorPos(handle, &_lastMouseX, &_lastMouseY);
    _mouse.x = _lastMouseX;
    _mouse.y = _lastMouseY;
}

/* ================================================================================ */
void InputManager::update() {
    // justPressed and justReleased are only true for one frame — clear them
    _keyJustPressed.fill(false);
    _keyJustReleased.fill(false);

    _mouse.deltaX = 0.0;
    _mouse.deltaY = 0.0;
}

/* ================================================================================ */
bool InputManager::isKeyDown(int key) const {
    if (key < 0 || key >= KEY_COUNT) return false;
    return _keyDown[key];
}

bool InputManager::wasJustPressed(int key) const {
    if (key < 0 || key >= KEY_COUNT) return false;
    return _keyJustPressed[key];
}

bool InputManager::wasJustReleased(int key) const {
    if (key < 0 || key >= KEY_COUNT) return false;
    return _keyJustReleased[key];
}

/* ================================================================================ */
void InputManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    (void)scancode;  // raw hardware key code, we use the GLFW abstracted `key` instead
    (void)mods;      // modifier keys (shift, ctrl, alt) — not using them yet
    
    // retrieve our InputManager from the window user pointer
    InputManager* self = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (!self || key < 0 || key >= KEY_COUNT) return;

    if (action == GLFW_PRESS) {
        self->_keyDown[key]        = true;
        self->_keyJustPressed[key] = true;
    } else if (action == GLFW_RELEASE) {
        self->_keyDown[key]         = false;
        self->_keyJustReleased[key] = true;
    }
    // GLFW_REPEAT intentionally ignored — use isKeyDown() for held keys
}

/* ================================================================================ */
void InputManager::cursorCallback(GLFWwindow* window, double x, double y) {
    InputManager* self = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
    if (!self) return;

    self->_mouse.deltaX = x - self->_lastMouseX;
    self->_mouse.deltaY = y - self->_lastMouseY;
    self->_lastMouseX   = x;
    self->_lastMouseY   = y;
    self->_mouse.x      = x;
    self->_mouse.y      = y;
}