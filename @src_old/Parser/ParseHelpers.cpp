#include "ParseHelpers.hpp"

#include <algorithm>
#include <sstream>
#include <stdexcept>

/* ==================================================================================== */

namespace {

/* "1.0,2.0,-3.5" -> (1.0, 2.0, -3.5) */
bool ParseTriplet(const std::string& raw, double& a, double& b, double& c)
{
	std::string s = raw;
	std::replace(s.begin(), s.end(), ',', ' ');

	std::istringstream ss(s);
	char dummy;
	return static_cast<bool>(ss >> a >> b >> c) && !(ss >> dummy);
}

/* "1.0" -> (1.0) */
bool ParseDouble(const std::string& raw, double& d)
{
	std::istringstream ss(raw);
	char dummy;

	return static_cast<bool>(ss >> d) && !(ss >> dummy);
}

} // namespace

/* ==================================================================================== */

Vec3 Parser::parseVec3(const std::map<std::string, std::string>& kv, const std::string& key, Vec3 fallback)
{
	auto it = kv.find(key);
	if (it == kv.end())
		return fallback;

	double x, y, z;
	if (!ParseTriplet(it->second, x, y, z))
		return fallback;

	return Vec3{x, y, z};
}

Color Parser::parseColor(const std::map<std::string, std::string>& kv, const std::string& key, Color fallback)
{
	auto it = kv.find(key);
	if (it == kv.end())
		return fallback;

	double r, g, b;
	if (!ParseTriplet(it->second, r, g, b))
		return fallback;

	Color color = fallback;
	color.r = r / 255.0;
	color.g = g / 255.0;
	color.b = b / 255.0;
	return color;
}

double Parser::parseDouble(const std::map<std::string, std::string>& kv, const std::string& key, double fallback)
{
	auto it = kv.find(key);
	if (it == kv.end())
		return fallback;

	try {
		return std::stod(it->second);
	} catch (const std::exception&) {
		return fallback;
	}
}


