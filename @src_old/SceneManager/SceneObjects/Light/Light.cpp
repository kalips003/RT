#include "Light.hpp"
#include "ParseHelpers.hpp"

/////////////////////////////////////////////////////////////////////////////////////////]
Light::Light() {}
Light::~Light() {}

/* ==================================================================================== */

void Light::fillObject(const std::map<std::string, std::string>& kv) {
	pos       = Parser::parseVec3(kv, "pos", pos);
	color     = Parser::parseColor(kv, "color", color);
	intensity = Parser::parseDouble(kv, "intensity", intensity);
}