#ifndef LIGHTSOURCE_HPP
#define LIGHTSOURCE_HPP

class Light {
public:
    Light() = default;

    Light(const TokenLine& t)
    {
        // position + intensity + color
    }

public:
    Vec3 position;
    Color color;
    double intensity = 1.0;
};

#endif
