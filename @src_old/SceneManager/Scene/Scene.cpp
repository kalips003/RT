#include "Scene.hpp"

#include <utility>

/////////////////////////////////////////////////////////////////////////////////////////]
Scene::Scene() {}
Scene::~Scene() {}

/* ==================================================================================== */

void Scene::addCamera(Camera camera)         { _cameras.push_back(std::move(camera)); }
void Scene::addLight(Light light)            { _lights.push_back(std::move(light)); }
void Scene::addSphere(Sphere sphere)         { _spheres.push_back(std::move(sphere)); }
void Scene::addPlane(Plane plane)            { _planes.push_back(std::move(plane)); }
void Scene::setAmbient(AmbientLight ambient) { _ambient = ambient; }