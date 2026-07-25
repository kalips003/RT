#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
// #include <vector>
// #include <map>
#include "_A.hpp"

/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class Sphere

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
class Sphere {

// ============	VARIABLES ============
public:
	// std::string		_name;
	vect3	origin;
	float	radius = 0.0f;
	vect3	color;

// ============ CONSTRUCTOR ============
public:
	Sphere();
	Sphere(vect3 o, float r, vect3 c) : origin(o), radius(r), color(c) {}
	~Sphere();

	Sphere(const Sphere &) = delete;
	Sphere& operator=(const Sphere&) = delete;

	Sphere(Sphere&&) noexcept = default;
	Sphere& operator=(Sphere&&) noexcept = default;


// ============ METHODS ============
public:
	/**	f:  */
	void	hello() { LOG_LOG("hello from " C_142 "Sphere" RESET); }
	void	f();
};













//================================================================================================]
//================================================================================================]
//================================================================================================]
std::ostream& operator<<(std::ostream& os, const Sphere& sphere);