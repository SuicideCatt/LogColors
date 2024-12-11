#pragma once

#include "Defines.hpp"

#include <cstdint>

namespace SCT::LogColors
{
	namespace DarkSide
	{
		template<uint8_t Color>
		struct _16_t
		{
			enum class c16 : uint8_t
			{
				black = Color,			red,
				green,					yellow,
				blue,					magenta,
				cyan,					light_gray,

				dark_gray = Color + 60,	light_red,
				light_green,			light_yellow,
				light_blue,				light_magenta,
				light_cyan,				white,

				reset = Color + 9,
			};
		};

		template<typename Type>
		struct _256_t
		{
			SCT_LC_INL consteval _256_t(uint8_t value);

			SCT_LC_INL operator uint8_t();

			uint8_t color = 0;
		};

		template<uint8_t Color>
		struct Colors : _16_t<Color>
		{
			using c256 = _256_t<_16_t<Color>>;
		};

		enum class Reset
		{
			reset
		};

		enum class Disable
		{
			off
		};
	}

	struct fg : DarkSide::Colors<30>
	{
		using enum c16;
	};

	struct bg : DarkSide::Colors<40>
	{
		using enum c16;
	};

	enum class form : uint8_t
	{
		bold = 0,	dim,	 italic,
		underline,	blink,	 invert,
		reversion,	canceal, strikethrough,

		reset = 9
	};

	using enum DarkSide::Reset;
	using enum DarkSide::Disable;
}

#include "tpp/Terminal.hpp"
