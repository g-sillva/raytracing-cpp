#include "camera.h"
#include "utils.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main() {

    // Materials
    std::shared_ptr material_lambertian_green = std::make_shared<lambertian>(color(0.8, 0.8, 0.0));
    std::shared_ptr material_lambertian_blue = std::make_shared<lambertian>(color(0.1, 0.2, 0.5));
    std::shared_ptr material_metal_light_gray = std::make_shared<metal>(color(0.8, 0.8, 0.8));
    std::shared_ptr material_metal_yellow = std::make_shared<metal>(color(0.8, 0.6, 0.2));

    // World
    hittable_list world;

    world.add(std::make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_lambertian_green));
    world.add(std::make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_lambertian_blue));
    world.add(std::make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_metal_light_gray));
    world.add(std::make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_metal_yellow));

    // Camera
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;
    
    cam.render(world);
}