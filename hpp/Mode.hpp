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
			if (this->form[5]) [[unlikely]]
			{
				switch (this->mode[0])
				{
				case _16:
					if (this->color[0] != 39)
						this->color[0] = 97 - this->color[0] + 30;
					break;
				case _256: // WHY??? WHY NOT.
						this->color[0] = 255 - this->color[0];
					break;
				
				default:
					break;
				}

				switch (this->mode[1])
				{
				case _16:
					if (this->color[1] != 49)
						this->color[1] = 107 - this->color[1] + 40;
					break;
				case _256: // WHY??? WHY NOT.
						this->color[1] = 255 - this->color[1];
					break;
				
				default:
					break;
				}
			}
		}

		inline void reset()
		{
			this->color[0] = 39;
			this->color[1] = 49;
			std::fill_n(this->mode, 2, _16);

			std::fill_n(this->form, 9, false);
			this->formClear = true;
		}
	};

	struct Print : public ColorEd { };
}