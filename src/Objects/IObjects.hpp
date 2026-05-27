#pragma once

// #include "Ray.hpp"
// #include "Hit.hpp"
#include "Material.hpp"
#include "general.hpp"

class IObject {

public:
    
    // Common data shared by all objects
    Point3      position;
    Vec3        axis;
    Material    material;

    virtual ~IObject() = default;

    // Core function: must be implemented by all objects
    // virtual bool intersect(const Ray& ray, Hit& hit) const = 0;

};