#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
#include <vector>
#include <memory>
// #include <map>

#include "Scene.hpp"

/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class SceneManager

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
class SceneManager {

// ============	VARIABLES ============
private:
	// std::string		_name;
	std::vector<std::unique_ptr<Scene>>		_scenes;

// ============ CONSTRUCTOR ============
public:
	SceneManager();
	~SceneManager();

	SceneManager(const SceneManager &) = delete;
	SceneManager& operator=(const SceneManager&) = delete;


// ============ METHODS ============
public:
	/**	f:  */
	void	hello() { LOG_LOG("hello from " C_142 "SceneManager" RESET); }
	void	f();

	bool	addScene() { return true; }
	bool	loadFromRTFile(const std::string& file_name);

// ============ GETTERS ============
	Scene& getFirstScene() { return *_scenes[0]; }
	Scene& getScene(size_t i) { return *_scenes[i]; }
};

