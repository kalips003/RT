#include "Engine.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////]
int main(int ac, char** av) {

    if (ac != 2) {
        std::cout << RED "one map required" RESET << std::endl;
        return 1;
    }

    Engine app;

    if (!app.init(av[1]))
        return 1;

    app.run();

    return 0;
}
