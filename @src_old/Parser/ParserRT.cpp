#include "Parser.hpp"
#include "ParseHelpers.hpp"

#include "Camera.hpp"
#include "Light.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

/* ==================================================================================== */

namespace {

struct TokenLine {
	std::string							objectType; // "camera", "light", "sphere", "plane"...
	std::map<std::string, std::string>	kv;         // size=<value>
};

std::string toLower(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(),
				[](unsigned char c){ return std::tolower(c); });
	return s;
}

/* Read the opened file, transform in vector of token lines */
std::vector<TokenLine> preParsingFile(std::ifstream& file)
{
	std::vector<TokenLine> rtrn;
	std::string line;
	TokenLine* current = nullptr;

	int i_line_num = 0;
	while (std::getline(file, line) && ++i_line_num)
	{
		if (line.empty() || line[0] == '#')
			continue;

		bool indented = std::isspace(line[0]);

		std::istringstream ss(line);

		// NEW OBJECT
		if (!indented) {

			std::string name;
			ss >> name;
			name = toLower(name);

			rtrn.push_back(TokenLine());
			current = &rtrn.back();
			current->objectType = name;

		}

		// KV LINE
		if (!current) {
			LOG_DEBUG(C_510 "strangely indented no named line (" << i_line_num << "):\n" RESET << line);
			continue;
		}

		std::string kv;
		while (ss >> kv) {

			size_t pos = kv.find_first_of('=');
			if (pos == std::string::npos) {
				LOG_ERROR(C_510 "unknown key_value pair: " RESET << kv);
				continue;
			}
			std::string key = toLower(kv.substr(0, pos));
			std::string value = kv.substr(pos + 1);
			current->kv[key] = value;
		}
	}

	return rtrn;
}

/* Wrapper of preParsingFile */
std::vector<TokenLine> openRTFile(const std::string& file) {

	std::ifstream rtScene(file);
	if (!rtScene.is_open()) {
		LOG_ERROR_SYS("cant open: " << file);
		throw std::runtime_error("cannot open file: " + file);
	}

	return preParsingFile(rtScene);
}

} // namespace

/* ==================================================================================== */

Scene Parser::parseRTFile(const std::string& filename, RessourceManager& resources) {

	(void)resources; // reserved for texture/mesh resolution once primitives carry material refs

	Scene scene;
	std::vector<TokenLine> tokens = openRTFile(filename);

	for (const TokenLine& line : tokens) {

		if (line.objectType == "camera") {
			Camera camera;
			camera.fillObject(line.kv);
			scene.addCamera(std::move(camera));
		}
		else if (line.objectType == "light") {
			Light light;
			light.fillObject(line.kv);
			scene.addLight(std::move(light));
		}
		else if (line.objectType == "sphere") {
			Sphere sphere;
			sphere.fillObject(line.kv);
			scene.addSphere(std::move(sphere));
		}
		else if (line.objectType == "plane") {
			Plane plane;
			plane.fillObject(line.kv);
			scene.addPlane(std::move(plane));
		}
		else if (line.objectType == "ambient") {
			AmbientLight ambient;
			ambient.ratio = Parser::parseDouble(line.kv, "ratio", ambient.ratio);
			ambient.color = Parser::parseColor(line.kv, "color", ambient.color);
			scene.setAmbient(ambient);
		}
		else
			LOG_WARNING("unknown object type: " << line.objectType);
	}

	return scene;
}
