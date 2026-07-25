#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
// #include <vector>
// #include <map>
#include "_A.hpp"


/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class Camera

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
class Camera {

// ============	VARIABLES ============
public:
	// std::string		_name;
	vect3	origin;
	vect3	dir;
	float	fov = 0.0f;

// ============ CONSTRUCTOR ============
public:
	Camera();
	Camera(vect3 o, vect3 r, float f) : origin(o), dir(r), fov(f) {}
	~Camera();

	Camera(const Camera &) = delete;
	Camera& operator=(const Camera&) = delete;
	
	Camera(Camera&&) noexcept = default;
	Camera& operator=(Camera&&) noexcept = default;


// ============ METHODS ============
public:
	/**	f:  */
	void	hello() { LOG_LOG("hello from " C_142 "Camera" RESET); }
	void	f();
};













//================================================================================================]
//================================================================================================]
//================================================================================================]
std::ostream& operator<<(std::ostream& os, const Camera& camera);