#pragma once

#include "Defines.hpp"

#include <cstdint>
#include <ostream>
#include <algorithm>

namespace SCT::LogColors::Mode
{
	struct Colored
	{
		enum Mode : char
		{
			_16, _256
		};

		std::ostream& out;

		uint16_t color[2] = {39, 49};
		Mode mode[2] = {_16, _16};

		bool form[9] = {};
		bool form_clear = true;

		SCT_LC_INL
		Colored(std::ostream& out);

		SCT_LC_INL
		void invert();

		SCT_LC_INL
		void reset_color();
		SCT_LC_INL
		void reset_formation();
		SCT_LC_INL
		void reset();
	};

	struct Print : public Colored {};
}

#include "ipp/Mode.hpp"
