#ifndef COLOR_H
#define COLOR_H

struct Color
{
  std::uint8_t r;
  std::uint8_t g;
  std::uint8_t b;

  constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept : r(r), g(g), b(b) {}

  Color() {}
};

#endif // COLOR_H