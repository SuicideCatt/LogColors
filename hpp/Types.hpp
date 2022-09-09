#pragma once

#include "Terminal.hpp"
#include "Mode.hpp"

namespace SCT::LogColors
{
	using fg = Terminal::FGColors;
	using bg = Terminal::BGColors;
	namespace form = Terminal::Formations;

	using namespace Terminal::Reset;

	using Config = Mode::ColorEd;
}