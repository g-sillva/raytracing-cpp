#include <iostream>

int main() {

    // Image size
    const int image_width = 256;
    const int image_height = 256;

    // Output image header
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    // Loop through each pixel row
    for (int j = 0; j < image_height; j++) {

        // Log scanline progress
        std::clog << "\rScanlines remaining: " << (image_height-j) << "\n" << std::flush;

        // Loop through each pixel in the row
        for (int i = 0; i < image_width; i++) {

            // Calculate color components based on pixel position
            double r = double(i) / (image_width-1);
            double g = double(j) / (image_height-1);
            double b = 0;

            // Convert color components to integer values
            int ir = static_cast<int>(255.999*r);
            int ig = static_cast<int>(255.999*g);
            int ib = static_cast<int>(255.999*b);

            // Output color values to create the image content
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    // Log completion
    std::clog << "\rDone.               \n";
}