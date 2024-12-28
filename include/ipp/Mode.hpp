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
				switch (vcolor.index())
				{
				case 0:
					{
						auto& color = std::get<0>(vcolor);
						using E = std::remove_reference_t<decltype(color)>;
						uint8_t& u8color = reinterpret_cast<uint8_t&>(color);

						if (color != E::reset)
						{
							constexpr uint8_t max =
								static_cast<uint8_t>(E::white);
							constexpr uint8_t min =
								static_cast<uint8_t>(E::black);

							u8color = max - u8color + min;
						}
					}
					break;
				case 1:
					{
						auto& color = std::get<1>(vcolor).color;
						color = ~color;
					}
					break;
				case 2:
					{
						auto& [r, g, b] = std::get<2>(vcolor);
						r = ~r;
						g = ~g;
						b = ~b;
					}
					break;
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

		auto color = [this](auto& color, const char* to_256, const char* to_rgb)
		{
			switch (color.index())
			{
			case 0:
				out << static_cast<uint64_t>(std::get<0>(color));
				break;
			[[unlikely]] case 1:
				out.write(to_256, 5);
				out << static_cast<uint64_t>(std::get<1>(color));
				break;
			[[unlikely]] case 2:
				{
					out.write(to_rgb, 5);
					auto& [r, g, b] = std::get<2>(color);
					out << static_cast<uint64_t>(r) << ';';
					out << static_cast<uint64_t>(g) << ';';
					out << static_cast<uint64_t>(b);
				}
				break;
			}
		};

		color(fg_color, "38;5;", "38;2;");
		out << ';';
		color(bg_color, "48;5;", "48;2;");
		out << 'm';

		try_invert();
	}
}
