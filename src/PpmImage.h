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
    typedef std::array<Color, T::x * T::y> StorageType;
    typedef typename StorageType::iterator iterator;

    StorageType data_;

public:
    PpmImage() : data_() {}

    static constexpr const std::size_t N_PIXELS = T::x * T::y;

    [[nodiscard]] bool write(const std::string &fileName) noexcept
    {
        std::ofstream filestream{};
        filestream.open(fileName, std::ofstream::out);

        // Write header
        filestream << "P3\n"
                   << T::x << ' '
                   << T::y << "\n255\n";

        for (auto &pixel : data_)
        {
            filestream << std::to_string(pixel.r) << ' ' << std::to_string(pixel.g) << ' ' << std::to_string(pixel.b) << '\n';
        }

        filestream.close();

        return true; // Always for now...
    }

    iterator begin() { return data_.begin(); }
    iterator end() { return data_.end(); }
};

#endif // PPM_IMAGE_H
