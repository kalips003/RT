#include "Camera.hpp"
#include "ParseHelpers.hpp"

/////////////////////////////////////////////////////////////////////////////////////////]
Camera::Camera() {}
Camera::~Camera() {}

/* ==================================================================================== */

void Camera::fillObject(const std::map<std::string, std::string>& kv) {
	pos = Parser::parseVec3(kv, "pos", pos);
	dir = Parser::parseVec3(kv, "dir", dir);
	fov = Parser::parseDouble(kv, "fov", fov);
}