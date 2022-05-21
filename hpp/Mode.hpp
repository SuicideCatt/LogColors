#pragma once

#include <ostream>
#include <algorithm>

namespace SCT::LogColors::Mode
{
    struct ColorEd
	{
		std::ostream& out;
		short int g[2] = {39, 49};
		bool form[9] = { };
		bool formClear = true;

		inline void invert()
		{
			if (this->form[5]) [[unlikely]]
			{
				if (this->g[0] != 39)
				{
					this->g[0] = 97 - this->g[0] + 30;
				}

				if (this->g[1] != 49)
				{
					this->g[1] = 107 - this->g[1] + 40;
				}
			}
		}

		inline void reset()
		{
			this->g[0] = 39;
			this->g[1] = 49;

			std::fill_n(this->form, 9, false);
			this->formClear = true;
		}
	};

	struct Print : public ColorEd { };
}