#pragma once

#include "Terminal.hpp"
#include "Mode.hpp"

namespace SCT::LogColors
{
	using fg = Terminal::FGColors::v;
	using bg = Terminal::BGColors::v;
	using form = Terminal::Formations::v;

	using enum Terminal::Reset;
	using enum Terminal::Delete;

	using Config = Mode::ColorEd;
}