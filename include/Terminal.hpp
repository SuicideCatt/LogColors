#pragma once

#include "Defines.hpp"

#include <cstdint>

namespace SCT::LogColors
{
	namespace DarkSide
	{
		template<uint16_t Color, uint16_t Id>
		struct _16_t
		{
			enum _16 : uint16_t
			{
				black = Color,         red,
				green,                 yellow,
				blue,                  magenta,
				cyan,                  ligftGray,

				darkGray = Color + 60, lightRed,
				lightGreen,            lightYellow,
				lightBlue,             lightMagenta,
				lightCyan,             white,

				reset = Color + 9,

				id = Id
			};
		};

		template<uint16_t Id>
		struct _256_t
		{
			SCT_LC_INL consteval _256_t(uint16_t value);

			SCT_LC_INL operator uint16_t();

			uint16_t color = 0;
			static constexpr uint8_t id = Id;
		};

		template<uint16_t Color, uint16_t Id>
		struct Colors : public _16_t<Color, Id>
		{
			using _256 = _256_t<Id>;
		};
	}

	using fg = DarkSide::Colors<30, 0>;
	using bg = DarkSide::Colors<40, 0>;

	namespace form
	{
		enum t : int8_t
		{
			bold = 0,  dim,     italic,
			underline, blink,   invert,
			reversion, canceal, strikethrough,

			reset = 9
		};
	}

	enum Reset
	{
		reset
	};

	enum Disable
	{
		off
	};
}

#include "tpp/Terminal.hpp"
