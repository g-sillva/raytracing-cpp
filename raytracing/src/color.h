#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "ray.h"

#include <iostream>

using color = vec3;

// Convert color components to integer values and output values
void write_color(std::ostream &out, color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << " "
        << static_cast<int>(255.999 * pixel_color.y()) << " "
        << static_cast<int>(255.999 * pixel_color.z()) << "\n";
}

// Generate color between white and light-blue (used for gradient)
color ray_color(const ray &r) {
    vec3 unit_direction = unit_vector(r.direction());
    double a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

#endif