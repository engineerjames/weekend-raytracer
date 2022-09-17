#ifndef PPM_IMAGE_H
#define PPM_IMAGE_H

#include <array>
#include <fstream>
#include <string>

#include "Color.h"

template <typename T>
concept Has2dSizeParameters = requires(T)
{
    T::x;
    T::y;
};

template <Has2dSizeParameters T>
class PpmImage
{
private:
    typedef std::array<Color, T::x * T::y> ArrayType;
    typedef typename ArrayType::iterator iterator;

    ArrayType data_;

public:
    PpmImage() : data_() {}

    static constexpr const std::size_t SIZE_X = T::x;
    static constexpr const std::size_t SIZE_Y = T::y;
    static constexpr const std::size_t N_PIXELS = T::x * T::y;

    void setPixel(const int x, const int y, const Color &color) noexcept
    {
        data_.at(y * SIZE_Y + x) = color;
    }

    [[nodiscard]] bool write(const std::string &fileName) noexcept
    {
        std::ofstream filestream{};
        filestream.open(fileName, std::ofstream::out);

        // Write header
        filestream << "P3\n"
                   << SIZE_X << ' '
                   << SIZE_Y << "\n255\n";

        for (int j = SIZE_Y - 1; j >= 0; --j)
        {
            std::cerr << j << std::endl;
            for (int i = 0; i < SIZE_X; ++i)
            {
                const auto index = j * SIZE_Y + i;
                const auto pixel = data_.at(index);

                filestream << std::to_string(pixel.r) << ' ' << std::to_string(pixel.g) << ' ' << std::to_string(pixel.b) << '\n';
            }
        }

        filestream.close();

        return true; // Always for now...
    }

    iterator begin() { return data_.begin(); }
    iterator end() { return data_.end(); }
};

#endif // PPM_IMAGE_H
