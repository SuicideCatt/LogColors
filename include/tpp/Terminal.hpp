#pragma once

#include "../Terminal.hpp"

namespace SCT::LogColors::DarkSide
{
	template<typename Type>
	SCT_LC_INL consteval _256_t<Type>::_256_t(uint8_t value)
		: color(value) {}

	template<typename Type>
	SCT_LC_INL _256_t<Type>::operator uint8_t()
		{ return color; }
}
