#include "general.hpp"
#include "Log.hpp"

class Camera {
public:
    Camera() = default;

    Camera(const TokenLine& t)
    {
        // position
        // direction
        // fov
        // (parse from t.kv later)
    }

public:
    Point3  _pos;
    Vec3    _axis;
    float   _fov = 60.0f;
};