#ifndef COLOR_H
#define COLOR_H

#include <iostream>

struct Color
{
  std::uint8_t r;
  std::uint8_t g;
  std::uint8_t b;

  constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept : r(r), g(g), b(b) {}

  Color &operator*(double scale)
  {
    if (scale > 1.0 || scale < 0.0)
    {
      std::cerr << "Invalid scale value!" << std::endl;
    }

    r = static_cast<std::uint8_t>(r * scale);
    g = static_cast<std::uint8_t>(g * scale);
    b = static_cast<std::uint8_t>(b * scale);

    return *this;
  }

  Color() {}
};

#endif // COLOR_H