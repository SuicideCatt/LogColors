#pragma once

#include "../Terminal.hpp"

namespace SCT::LogColors::DarkSide
{
	template<typename Type>
	SCT_LC_INL _256_t<Type>::_256_t(uint8_t value)
		: color(value) {}

	template<typename Type>
	SCT_LC_INL _256_t<Type>::operator uint8_t()
		{ return color; }

	template<typename Type>
	SCT_LC_INL rgb_t<Type>::rgb_t(uint8_t all)
		: r(all), g(all), b(all) {}

	template<typename Type>
	SCT_LC_INL rgb_t<Type>::rgb_t(uint8_t r, uint8_t g, uint8_t b)
		: r(r), g(g), b(b) {}
}
