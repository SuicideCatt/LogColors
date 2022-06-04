#pragma once

#include "Terminal.hpp"
#include "Mode.hpp"

namespace SCT::LogColors
{
	using fg = Terminal::FGColors;
	using bg = Terminal::BGColors;
	namespace form = Terminal::Formations;

	using enum Terminal::Reset;
	using enum Terminal::Delete;

	using Config = Mode::ColorEd;
}