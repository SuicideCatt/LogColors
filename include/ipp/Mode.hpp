#pragma once

#include "../Mode.hpp"

#define GenInvertMode(id, cid) \
	switch (mode[id]) \
	{ \
		case _16: \
			if (color[id] != (39 + cid)) \
				color[id] = (97 + cid) - color[id] + (30 + cid); \
			break; \
		case _256: \
			color[id] = 255 - color[id]; \
			break; \
		default: \
			break; \
	}


namespace SCT::LogColors::Mode
{
	SCT_LC_INL
	Colored::Colored(std::ostream& out) : out(out) {}

	SCT_LC_INL
	void Colored::invert()
	{
		if (form[5]) [[unlikely]]
		{
			GenInvertMode(0, 0)
			GenInvertMode(1, 10)
		}
	}

	SCT_LC_INL
	void Colored::reset_color()
	{
		color[0] = 39;
		color[1] = 49;
		std::fill_n(mode, 2, _16);
	}

	SCT_LC_INL
	void Colored::reset_formation()
	{
		std::fill_n(form, 9, false);
		form_clear = true;
	}

	SCT_LC_INL
	void Colored::reset()
	{
		reset_color();
		reset_formation();
	}
}

#undef GenInvertMode
