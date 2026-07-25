#include "SceneManager.hpp"

#include <utility>

/////////////////////////////////////////////////////////////////////////////////////////]
SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

/* ==================================================================================== */

void SceneManager::addScene(Scene scene) {
	_scenes.push_back(std::make_unique<Scene>(std::move(scene)));
}