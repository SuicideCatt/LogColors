#pragma once

#include <ostream>
#include <algorithm>

namespace SCT::LogColors::Mode
{
    struct ColorEd
	{
		enum Mode : char
		{
			_16, _256
		};

		std::ostream& out;

		short int color[2] = {39, 49};
		Mode mode[2] = {_16, _16};

		bool form[9] = { };
		bool formClear = true;

		inline void invert()
		{
			if (form[5]) [[unlikely]]
			{
				switch (mode[0])
				{
				case _16:
					if (color[0] != 39)
						color[0] = 97 - color[0] + 30;
					break;
				case _256: // WHY??? WHY NOT.
						color[0] = 255 - color[0];
					break;
				
				default:
					break;
				}

				switch (mode[1])
				{
				case _16:
					if (color[1] != 49)
						color[1] = 107 - color[1] + 40;
					break;
				case _256: // WHY??? WHY NOT.
						color[1] = 255 - color[1];
					break;
				
				default:
					break;
				}
			}
		}

		inline void reset()
		{
			color[0] = 39;
			color[1] = 49;
			std::fill_n(mode, 2, _16);

			std::fill_n(form, 9, false);
			formClear = true;
		}
	};

	struct Print : public ColorEd { };
}