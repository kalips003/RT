#include "Sphere.hpp"
#include "ParseHelpers.hpp"

/////////////////////////////////////////////////////////////////////////////////////////]
Sphere::Sphere() {}
Sphere::~Sphere() {}

/* ==================================================================================== */

void Sphere::fillObject(const std::map<std::string, std::string>& kv) {
	pos    = Parser::parseVec3(kv, "pos", pos);
	dir    = Parser::parseVec3(kv, "dir", dir);
	radius = Parser::parseDouble(kv, "radius", radius);
	color  = Parser::parseColor(kv, "color", color);
}