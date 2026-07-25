#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
// #include <vector>
// #include <map>
#include <memory>

#include "Scene.hpp"

/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class Parser

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
namespace Parser {

	std::unique_ptr<Scene>	ParseRT(const std::string& name);


};

