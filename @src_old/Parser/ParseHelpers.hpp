#pragma once

#include <map>
#include <string>

#include "math_structs.hpp"

/* ================================================================================ */
/* Generic "read this key from a kv map, or fall back to a default" helpers,
   shared by every SceneObject's fillObject(). */

namespace Parser {

Vec3	parseVec3(const std::map<std::string, std::string>& kv, const std::string& key, Vec3 fallback);
Color	parseColor(const std::map<std::string, std::string>& kv, const std::string& key, Color fallback);
double	parseDouble(const std::map<std::string, std::string>& kv, const std::string& key, double fallback);

} // namespace Parser
