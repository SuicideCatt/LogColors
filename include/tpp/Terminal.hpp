#pragma once

#include "../Terminal.hpp"

namespace SCT::LogColors::DarkSide
{
	void error(const char*);

	template<uint16_t Id>
	SCT_LC_INL consteval _256_t<Id>::_256_t(uint16_t value) : color(value)
	{
		if (value > 255) error("Dude, color value more than 255");
	}

	template<uint16_t Id>
	SCT_LC_INL _256_t<Id>::operator uint16_t()
		{ return color; }
}
