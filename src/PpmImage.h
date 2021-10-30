#ifndef PPM_IMAGE_H
#define PPM_IMAGE_H

#include <array>

#include "Color.h"
#include "Point.h"

template<typename T>
concept Has2dSizeParameters = requires(T)
{
	T::x;
	T::y;
};

template< Has2dSizeParameters T >
class PpmImage
{
private: 
	std::array<Color, T::x * T::y> data_;

public:
	PpmImage() : data_() { }

	struct iterator
	{
		typedef std::random_access_iterator_tag iterator_category;
		typedef Color value_type;
		typedef std::ptrdiff_t difference_type;
		typedef Color* pointer;
		typedef Color& reference;

		iterator(pointer ptr) : ptr_(ptr) { }

		reference operator*() const { return *ptr_; }
		pointer operator->() { return ptr_; }

		iterator& operator++() { ptr_++; return *this; }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

	private:
		pointer ptr_;
	};

	iterator begin() { return iterator{ &data_[0] }; }
	iterator end() { return iterator{ &data_[T::x * T::y] }; }
};

#endif // PPM_IMAGE_H
