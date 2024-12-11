#pragma once

#include "../Mode.hpp"

namespace SCT::LogColors::Mode
{
	SCT_LC_INL Config::Config(std::ostream& out)
		: out(out), fg_color(fg::reset), bg_color(bg::reset),
		  form{}, form_clear(true) {}

	SCT_LC_INL void Config::try_invert()
	{
		if (form[static_cast<uint8_t>(form::invert)]) [[unlikely]]
		{
			auto invert_color = [](auto& vcolor)
			{
				if (vcolor.index())
				{
					auto& color = std::get<1>(vcolor).color;
					color = ~color;
				}
				else
				{
					auto& color = std::get<0>(vcolor);
					using E = std::remove_reference_t<decltype(color)>;
					uint8_t& u8color = reinterpret_cast<uint8_t&>(color);

					if (color != E::reset)
					{
						constexpr uint8_t max = static_cast<uint8_t>(E::white);
						constexpr uint8_t min = static_cast<uint8_t>(E::black);

						u8color = max - u8color + min;
					}
				}
			};

			invert_color(fg_color);
			invert_color(bg_color);
		}
	}

	SCT_LC_INL void Config::reset()
	{
		reset_colors();
		reset_formation();
	}

	SCT_LC_INL void Config::reset_colors()
	{
		fg_color = fg::reset;
		bg_color = bg::reset;
	}

	SCT_LC_INL void Config::reset_formation()
	{
		std::fill_n(form, 9, false);
		form_clear = true;
	}

	SCT_LC_INL void Config::print_reset()
		{ out.write("\033[0m", 4); }

	SCT_LC_INL void Printing::print_formation()
	{
		out.write("\033[0;", 4);

		for (uint16_t i = 0; i < 9 && !form_clear; ++i)
			if (i != 5 && form[i])
				out << i + 1 << ';';

		try_invert();

		auto color = [this](auto& color, const char* to_256)
		{
			if (color.index()) [[unlikely]]
			{
				out.write(to_256, 5);
				out << static_cast<uint64_t>(std::get<1>(color));
			}
			else
			{
				out << static_cast<uint64_t>(std::get<0>(color));
			}
		};

		color(fg_color, "38;5;");
		out << ';';
		color(bg_color, "48;5;");
		out << 'm';

		try_invert();
	}
}
