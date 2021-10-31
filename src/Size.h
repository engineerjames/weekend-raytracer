#ifndef SIZE_H
#define SIZE_H

template<std::size_t WIDTH, std::size_t HEIGHT>
struct Size
{
    static constexpr const std::size_t x = WIDTH;
    static constexpr const std::size_t y = HEIGHT;
};

#endif // SIZE_H