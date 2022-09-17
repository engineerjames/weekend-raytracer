#include <iostream>

#include "Color.h"
#include "PpmImage.h"
#include "Size.h"

#include "Vector.h"

PpmImage<Size<256, 256>> image{};

int main()
{
    static std::size_t progress = 0;

    for (int j = image.SIZE_Y - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image.SIZE_X; ++i)
        {
            auto r = double(i) / (image.SIZE_X - 1);
            auto g = double(j) / (image.SIZE_Y - 1);
            auto b = 0.25;

            std::uint8_t ir = static_cast<std::uint8_t>(255.999 * r);
            std::uint8_t ig = static_cast<std::uint8_t>(255.999 * g);
            std::uint8_t ib = static_cast<std::uint8_t>(255.999 * b);

            Color colorToWrite{ir, ig, ib};

            image.setPixel(i, j, colorToWrite);
        }
    }

    std::cerr << "\nWriting image to disk.\n";
    bool success = image.write("test.ppm");

    return 0;
}
