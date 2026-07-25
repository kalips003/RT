#pragma once
#include "Log.hpp"
#include "math_structs.hpp"
#include <map>
#include <string>

/////////////////////////////////////////////////////////////////////////////////////////]
// 									LIBs

/////////////////////////////////////////////////////////////////////////////////////////]
// 									CLASS
/////////////////////////////////////////////////////////////////////////////////////////]

class Sphere {

//
public:
	Sphere();
	~Sphere();

	Sphere(const Sphere &) = default;
	Sphere& operator=(const Sphere&) = default;

	Sphere(Sphere&&) noexcept = default;
	Sphere& operator=(Sphere&&) noexcept = default;

	void fillObject(const std::map<std::string, std::string>& kv);

	Vec3	pos;
	Vec3	dir = {1.0, 0.0, 0.0}; // axis, reserved for future texture mapping
	double	radius = 0.0;
	Color	color;

};

