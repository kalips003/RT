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

class Camera {

//
public:
	Camera();
	~Camera();

	Camera(const Camera &) = default;
	Camera& operator=(const Camera&) = default;

	Camera(Camera&&) noexcept = default;
	Camera& operator=(Camera&&) noexcept = default;

	void fillObject(const std::map<std::string, std::string>& kv);

	Vec3	pos;
	Vec3	dir;
	double	fov = 0.0;

};

