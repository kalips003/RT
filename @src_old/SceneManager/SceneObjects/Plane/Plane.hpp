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

class Plane {

//
public:
	Plane();
	~Plane();

	Plane(const Plane &) = default;
	Plane& operator=(const Plane&) = default;

	Plane(Plane&&) noexcept = default;
	Plane& operator=(Plane&&) noexcept = default;

	void fillObject(const std::map<std::string, std::string>& kv);

	Vec3	pos;
	Vec3	dir; // normal
	Color	color;

};
