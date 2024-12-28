#define USE_SCT_LC
#include <LogColors.hpp>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

void print_val(std::string val)
{
	std::cout << "  " << std::quoted(val) << " is ";

	std::ranges::replace(val, '\033', '\\');
	std::cout << std::quoted(val) << '\n';
}

template<typename Colors, uint8_t offset>
void test_color16()
{
	constexpr uint8_t begin = static_cast<uint8_t>(Colors::black) + offset;
	constexpr uint8_t end = static_cast<uint8_t>(Colors::light_gray) + offset;

	for (uint8_t c = begin; c < end + 1; ++c)
	{
		std::stringstream ss;
		ss << static_cast<Colors::c16>(c) << "Text" << LC::off;
		print_val(ss.str());
	}
}

template<typename Colors>
void test_color256()
{
	for (uint16_t c = 0; c < 256; ++c)
	{
		std::stringstream ss;
		ss << typename Colors::c256(c) << "Text" << LC::off;
		print_val(ss.str());
	}
}

template<LC::Concepts::IsFG fg_t, LC::Concepts::IsBG bg_t>
void test_formation(fg_t fg, bg_t bg)
{
	for (uint8_t c = 0; c < 9; ++c)
	{
		std::stringstream ss;
		ss << fg << bg << static_cast<LC::form>(c) << "Text" << LC::off;
		print_val(ss.str());
	}
}

void test_just_text()
{
	std::stringstream ss;

	// Line 1 - All text is white and bold.
	// Line 2 - One white, italic word on a black background.
	//          Apply bold formatting twice (to disable it).
	// Line 3 - Reset all styles, print a word, then disable formatting.

	ss << LC::form::bold << LC::fg::white << "White text on " // L1
	   << LC::form::italic << LC::form::bold << LC::bg::black << "black" // L2
	   << LC::reset << " background" << LC::off; // L3

	print_val(ss.str());
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

	std::cout << "\n\n";

	std::cout << "Test formation\n";
	test_formation(LC::fg::light_magenta, LC::bg::c256(50));

	std::cout << "\n\n";

	std::cout << "Just text\n";
	test_just_text();
}
