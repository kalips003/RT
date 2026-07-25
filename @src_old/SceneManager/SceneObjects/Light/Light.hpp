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

class Light {

//
public:
	Light();
	~Light();

	Light(const Light &) = default;
	Light& operator=(const Light&) = default;

	Light(Light&&) noexcept = default;
	Light& operator=(Light&&) noexcept = default;

	void fillObject(const std::map<std::string, std::string>& kv);

	Vec3	pos;
	Color	color;
	double	intensity = 0.0; // 0.0 - 1.0

};

