#include <iostream>

#include "Color.h"
#include "PpmImage.h"
#include "Size.h"

#include "Vector.h"

PpmImage<Size<256, 256>> image{};

int main()
{
    Color colorToWrite{};
    colorToWrite.b = 65;

    static std::size_t progress = 0;
    for (auto &pixel : image)
    {
        colorToWrite.r += 1;
        colorToWrite.g -= 1;

        pixel = colorToWrite;

        progress += 1;

        std::cerr << "\rScanlines remaining: "
                  << (PpmImage<Size<256, 256>>::N_PIXELS - progress);
    }

    std::cerr << "\nWriting image to disk.\n";
    bool success = image.write("test.ppm");

    return 0;
}
