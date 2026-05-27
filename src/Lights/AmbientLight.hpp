#ifndef AMBIENTLIGHT_HPP
#define AMBIENTLIGHT_HPP

#include "general.hpp"

class AmbientLight {
public:
    AmbientLight() = default;

    AmbientLight(const TokenLine& t)
    {
        // ratio + color (parse later from kv)
    }

public:
    double ratio = 0.1;
    Color color = {1,1,1};
};

#endif