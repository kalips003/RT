#include <SDL2/SDL.h>
#include <Log.hpp>

#include "Scene.hpp"

class Engine {

public:
    Engine() : _window(nullptr), _renderer(nullptr) {}
    ~Engine();

public:
    bool init(const std::string& mapFile);
    void run();

private:
    SDL_Window*     _window;
    SDL_Renderer*   _renderer;

    Scene           _scene;
    SDL_Event       _events;

private:
    void handleEvents(bool& running);
    void updateLogic();
    void renderFrame();

};
