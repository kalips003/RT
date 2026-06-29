#include "Log.hpp"
#include "App.hpp"
#include "defines.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////]
int main(int ac, char** av) {

	if (ac != 2) {
		std::cout << RED "one map required" RESET << std::endl;
		return 1;
	}

	Log& logger = Log::instance();
	if (!logger.getStatus()) {
		std::cerr << RED "Log failed to setup" RESET << std::endl;
		return 0;
	}
		
	try {
		App app(SIZE_SCREEN_X, SIZE_SCREEN_Y, "Engine");
		LOG_HERE(RED "we did it !" RESET);
		app.run();
	} catch (const std::exception& e) {
		std::cerr << "Fatal: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
