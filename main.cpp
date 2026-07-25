#include "Log.hpp"
#include "_A.hpp"
#include "defines.hpp"

#include <iostream>

#include "App.hpp"
#include "SceneManager.hpp"

///////////////////////////////////////////////////////////////////////////////]
int main(int ac, char** av) {

	SceneManager manager;

	if (av[1]) {
		manager.loadFromRTFile(av[1]);
		LOG_DEBUG(manager.getFirstScene())
	}

	return 0;
}
