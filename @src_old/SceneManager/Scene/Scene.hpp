#pragma once
#include "Log.hpp"
#include <vector>

/////////////////////////////////////////////////////////////////////////////////////////]
// 									LIBs

#include "math_structs.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

/////////////////////////////////////////////////////////////////////////////////////////]
// 									CLASS
/////////////////////////////////////////////////////////////////////////////////////////]

class Scene {

//
public:
	Scene();
	~Scene();

	Scene(const Scene &) = delete;
	Scene& operator=(const Scene&) = delete;

	Scene(Scene&&) noexcept = default;
	Scene& operator=(Scene&&) noexcept = default;

	void addCamera(Camera camera);
	void addLight(Light light);
	void addSphere(Sphere sphere);
	void addPlane(Plane plane);
	void setAmbient(AmbientLight ambient);

//
private:
	std::vector<Camera>	_cameras;
	std::vector<Light>		_lights;
	std::vector<Sphere>	_spheres;
	std::vector<Plane>		_planes;
	AmbientLight			_ambient;

};

