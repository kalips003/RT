#pragma once

#include <string>

#include "Log.hpp"
#include "Scene.hpp"
#include "RessourceManager.hpp"

/* ================================================================================ */

namespace Parser {

Scene parseRTFile(const std::string& filename, RessourceManager& resources);

} // namespace Parser
