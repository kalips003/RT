#include "Log.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////]
int main(int ac, char** av) {

    std::cout << RED "Hi gorgeous!~" RESET << std::endl;

    if (ac != 2) {
        std::cout << RED "one map required" RESET << std::endl;
        return 1;
    }

	Log& logger = Log::instance();
	if (!logger.getStatus()) {
		std::cerr << RED "Log failed to setup" RESET << std::endl;
		return 0;
	}
    
    // Engine app;

    // if (!app.init(av[1]))
    //     return 1;

    // app.run();

    return 0;
}
