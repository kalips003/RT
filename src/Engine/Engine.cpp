#include <iostream>
#include "defines.hpp"
#include "Engine.hpp"
#include "Parser.hpp"

///////////////////////////////////////////////////////////////////////////////]
Engine::~Engine()
{
    if (_renderer)
        SDL_DestroyRenderer(_renderer);
    if (_window)
        SDL_DestroyWindow(_window);

    SDL_Quit();
}

///////////////////////////////////////////////////////////////////////////////]
bool    Engine::init(const std::string& mapFile) {

// Logger
	Log& logger = Log::instance();
	if (!logger.getStatus()) {
		std::cerr << RED "Log failed to setup" RESET << std::endl;
		return false;
	}

// Map parsing
    if (!Parser::loadRT(mapFile, _scene)) {
		std::cerr << RED "Map incorrect" RESET << std::endl;
		return false;
    }

// Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << RED "SDL_Init Error: " RESET << SDL_GetError() << std::endl;
        return false;
    }

// Create window
    this->_window = SDL_CreateWindow(
        "MiniRT SDL2",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SIZE_SCREEN_X,
        SIZE_SCREEN_Y,
        SDL_WINDOW_SHOWN
    );

    if (!_window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

// Create renderer
    this->_renderer = SDL_CreateRenderer(
        _window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (!_renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}


///////////////////////////////////////////////////////////////////////////////]
void Engine::run() {

    bool running = true;

    while (running) {
        handleEvents(running);
        updateLogic();
        renderFrame();
    }
}

///////////////////////////////////////////////////////////////////////////////]
void Engine::handleEvents(bool& running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            running = false;
    }
}

///////////////////////////////////////////////////////////////////////////////]
void Engine::updateLogic() {
    // nothing yet
}

///////////////////////////////////////////////////////////////////////////////]
void Engine::renderFrame() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);

    // later: render scene

    SDL_RenderPresent(_renderer);
}