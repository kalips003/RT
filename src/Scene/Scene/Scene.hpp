#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
#include <vector>
// #include <map>

#include "Camera.hpp"
#include "LightSource.hpp"
#include "Sphere.hpp"
#include "Plan.hpp"

/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class Scene

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
class Scene {

// ============	VARIABLES ============
public:
	// std::string		_name;
	std::vector<Camera>			_cameras;
	std::vector<LightSource>	_lightsources;
	std::vector<Sphere>			_spheres;
	std::vector<Plan>			_plans;

// ============ CONSTRUCTOR ============
public:
	Scene();
	~Scene();

	Scene(const Scene &) = delete;
	Scene& operator=(const Scene&) = delete;


// ============ METHODS ============
public:
	/**	f:  */
	void	hello() { LOG_LOG("hello from " C_142 "Scene" RESET); }
	void	f();
};








//================================================================================================]
//================================================================================================]
//================================================================================================]
#include <ostream>
std::ostream& operator<<(std::ostream& os, const Scene& scene);