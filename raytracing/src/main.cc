#include "utils.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

// Generate color between white and light-blue (used for gradient)
color ray_color(const ray &r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, interval(0, infinity), rec)) {
        return 0.5 * (rec.normal + color(1, 1, 1));
    }

    vec3 unit_direction = unit_vector(r.direction());
    double a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;

    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height; // Ensure image height it at least 1

    // World
    hittable_list world;

    world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100));
    world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5));

    // Camera
    const double focal_length = 1.0;
    const double viewport_height = 2.0;
    const double viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
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
            point3 pixel_position = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            vec3 ray_direction = pixel_position - camera_position;
            ray r(camera_position, ray_direction);

            color pixel_color = ray_color(r, world);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.               \n";
}