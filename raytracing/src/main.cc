#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

int main() {

    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;

    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height; // Ensure image height it at least 1

    // Camera
    const double focal_length = 1.0;
    const double viewport_height = 2.0;
    const double viewport_width = viewport_height * (static_cast<double>(image_width / image_height));
    const point3 camera_position = point3(0, 0, 0);

    const vec3 viewport_u = vec3(viewport_width, 0, 0);   // Horizontal vector of viewport
    const vec3 viewport_v = vec3(0, -viewport_height, 0); // Vertical vector of viewport

    const vec3 pixel_delta_u = viewport_u / image_width;  // Horizontal delta vector from pixel to pixel
    const vec3 pixel_delta_v = viewport_v / image_height; // Vertical delta vector from pixel to pixel

    // Location of the upper left pixel
    const vec3 viewport_upper_left = camera_position - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    const vec3 pixel00_loc = viewport_upper_left + (pixel_delta_u + pixel_delta_v) * 0.5;

    // Output image header
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height-j) << "\n" << std::flush;

        for (int i = 0; i < image_width; i++) {
            point3 pixel_position = pixel00_loc + (pixel_delta_u * i)+(pixel_delta_v * j);
            vec3 ray_direction = pixel_position - camera_position;
            ray r(camera_position, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.               \n";
}