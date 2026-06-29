#pragma once
#include "Log.hpp"
#include "Window.hpp"
#include <memory>
#include <vector>
#include <string>

class WindowManager {
public:
    WindowManager();
    ~WindowManager();

    WindowManager(const WindowManager&)            = delete;
    WindowManager& operator=(const WindowManager&) = delete;

    Window& createWindow(int width, int height, const std::string& title);
    Window& getMainWindow();
    void    pollEvents() const;

private:
    std::vector<std::unique_ptr<Window>> _windows;
};