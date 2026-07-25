#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
// #include <Scene.hpp>
#include <Log.hpp>

struct Color {
    double a = 1.0;
    double r = 1.0;
    double g = 1.0;
    double b = 1.0;
};

struct AmbientLight {
    double ratio = 0.0;
    Color  color;
};

struct Point3 {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

struct Vec3 {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

struct Quaternion
{
    float w;
    float x;
    float y;
    float z;

    Quaternion()
        : w(1.0f), x(0.0f), y(0.0f), z(0.0f)
    {}

    Quaternion(float w, float x, float y, float z)
        : w(w), x(x), y(y), z(z)
    {}
};

struct Transform
{
    Vec3 position = {1.0,1.0,1.0};
    Quaternion rotation;
    Vec3 scale;
};

/* ================================================================================ */

#endif