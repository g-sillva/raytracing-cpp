#ifndef RAY_H
#define RAY_H

#include "vec3.h"

// Class to represent a ray
class ray {
    public:

        // Constructors
        ray() {}
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        // Accessors (getters)
        point3 origin() const { return orig; }
        vec3 direction() const { return dir; }

        // Return the position of the ray at time t
        point3 at(double t) const {
            return orig + (dir * t);
        }

    private:
        point3 orig; // origin of the ray
        vec3 dir;    // direction the ray is going
};


#endif