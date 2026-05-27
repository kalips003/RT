#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>
#include "IObjects.hpp"
#include "LightSource.hpp"
#include "AmbientLight.hpp"
#include "Camera.hpp"

class Scene {
public:
    void add(std::unique_ptr<IObject> obj);
    void add(const Light& light);
    void add(const Camera& cam);
    void add(const AmbientLight& ambient);

private:
    std::vector<std::unique_ptr<IObject>> _objects;
    std::vector<Light> _lights;
    std::vector<Camera> _cameras;
    AmbientLight        _ambient;

    // RessourceManager    _RManager;
};

#endif