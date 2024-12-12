#define USE_SCT_LC
#include <LogColors.hpp>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

void print_val(std::string val)
{
	std::cout << "  " << val;
}

template<typename Colors>
concept Is16 = LC::Concepts::IsFG_16<Colors> || LC::Concepts::IsBG_16<Colors>;

template<Is16 Colors>
std::string_view to_string(Colors color)
{
	#define LAZY_CASE(name) case Colors::name: return #name;

	switch (color)
	{
	LAZY_CASE(black);
	LAZY_CASE(red);
	LAZY_CASE(green);
	LAZY_CASE(yellow);
	LAZY_CASE(blue);
	LAZY_CASE(magenta);
	LAZY_CASE(cyan);
	LAZY_CASE(light_gray);

	LAZY_CASE(dark_gray);
	LAZY_CASE(light_red);
	LAZY_CASE(light_green);
	LAZY_CASE(light_yellow);
	LAZY_CASE(light_blue);
	LAZY_CASE(light_magenta);
	LAZY_CASE(light_cyan);
	LAZY_CASE(white);
	}

	return "";
}

template<typename Colors, uint8_t offset>
void test_color16()
{
	constexpr uint8_t begin = static_cast<uint8_t>(Colors::black) + offset;
	constexpr uint8_t end = static_cast<uint8_t>(Colors::light_gray) + offset;

	for (uint8_t c = begin; c < end + 1; ++c)
	{
		auto ce = static_cast<Colors::c16>(c);
		std::stringstream ss;
		ss << ce << to_string(ce) << LC::off;
		print_val(ss.str());
	}
	std::cout << '\n';
}

template<typename Colors>
void test_color256()
{
	for (uint16_t c = 0; c < 256;)
	{
		uint16_t e = c + 8;
		for (; c < e; ++c)
		{
			std::stringstream ss;
			ss << typename Colors::c256(c) << std::setw(3) << +c << LC::off;
			print_val(ss.str());
		}
		std::cout << '\n';
	}
}

int main()
{
	std::cout << "Test fg 16 colors:\n";
	test_color16<LC::fg, 0>();
	test_color16<LC::fg, 60>();

	std::cout << "Test bg 16 colors:\n";
	test_color16<LC::bg, 0>();
	test_color16<LC::bg, 60>();

	std::cout << "\n\n";

	std::cout << "Test fg 256 colors\n";
	test_color256<LC::fg>();
	std::cout << "Test bg 256 colors\n";
	test_color256<LC::bg>();
}
