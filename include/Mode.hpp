#pragma once

#include "Terminal.hpp"

#include <ostream>
#include <variant>

namespace SCT::LogColors::Mode
{
	struct Config
	{
		template<typename T>
		using Color = std::variant<typename T::c16, typename T::c256,
								   typename T::rgb>;

		SCT_LC_INL Config(std::ostream& out);

		SCT_LC_INL void try_invert();

		SCT_LC_INL void reset();
		SCT_LC_INL void reset_colors();
		SCT_LC_INL void reset_formation();

		SCT_LC_INL void print_reset();

		std::ostream& out;

		Color<fg> fg_color;
		Color<bg> bg_color;

		bool form[9];
		bool form_clear;
	};

	struct Printing : Config
	{
		SCT_LC_INL void print_formation();
	};
}

#include "ipp/Mode.hpp"
