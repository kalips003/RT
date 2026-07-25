#include "Plane.hpp"
#include "ParseHelpers.hpp"

/////////////////////////////////////////////////////////////////////////////////////////]
Plane::Plane() {}
Plane::~Plane() {}

/* ==================================================================================== */

void Plane::fillObject(const std::map<std::string, std::string>& kv) {
	pos   = Parser::parseVec3(kv, "pos", pos);
	dir   = Parser::parseVec3(kv, "dir", dir);
	color = Parser::parseColor(kv, "color", color);
}
