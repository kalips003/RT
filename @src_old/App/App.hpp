#pragma once

#include <string>

#include "Log.hpp"
#include "WindowManager.hpp"
#include "InputManager.hpp"
#include "Renderer.hpp"
#include "SceneManager.hpp"
#include "RessourceManager.hpp"

class App {

public:
	App(int width, int height, const char* title);
	~App() = default;

	void run();
	void openRTFile(const std::string& file_name);

private:
	void processInput();
    void update();

	WindowManager	_windowManager;
	Window&			_mainWindow;
	InputManager  	_inputManager;
	Renderer      	_renderer;
	RessourceManager	_resourceManager;
	SceneManager		_sceneManager;

    bool _drawTriangle = false;
    bool _drawQuad     = false;
    bool  _drawBlue     = false;
    float _blueX        = 0.0f;   // NDC position of blue triangle
    float _blueY        = 0.0f;
};


/*

Core Architecture
App
The root owner. Holds everything by value or unique_ptr. Drives the main loop. Nothing else should own top-level systems.
App
├── WindowManager
├── ResourceManager
├── InputManager
├── SceneManager        ← you'll want this
└── Renderer            ← separate from WindowManager

WindowManager
Owns the OpenGL context(s) and GLFW/SDL window handles. If you have multiple windows, each window probably wraps its own context or shares one. Responsible for swap buffers, vsync, resize events.

ResourceManager
Owns all GPU/CPU assets: textures, meshes, shaders, materials. Hands out handles or raw pointers (never ownership). Uses a cache keyed by path/id so the same asset isn't loaded twice. This is your only class that calls glGenTextures, glDeleteTextures, etc.

InputManager
Polls or receives events from the windowing layer. Exposes a clean query API (isKeyDown, wasKeyJustPressed, getMouseDelta). Doesn't own windows but reads from them.

SceneManager (you're missing this)
For a raytracer/game engine you need something that owns the scene graph: cameras, lights, objects, materials references. In RT42 this is basically your parsed world. Without this, App becomes a dumping ground.

Renderer
Separate from WindowManager. Takes the scene, knows about shaders and draw calls. In RT context this is your raytracing pipeline. It borrows resources from ResourceManager, never owns them.

InitManager → reconsider the name
What you're describing is really a SceneLoader or ConfigParser. It reads the .rt file, builds the scene, then its job is done. It shouldn't persist as a manager — it's a one-shot utility. The result it produces lives in SceneManager.



Things worth flagging early

Entity system: once your scene has many object types, a flat list breaks down. Even a simple component model saves you later.
Event bus vs direct calls: InputManager notifying other systems — do you poll or publish events? Decide early.
GL context threading: if you ever go multithreaded, the GL context must stay on one thread. ResourceManager needs to account for this.

*/