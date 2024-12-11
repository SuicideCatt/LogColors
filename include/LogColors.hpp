#pragma once

#include "Defines.hpp"
#include "Mode.hpp"
#include "Terminal.hpp"
#include "tpp/Operators.hpp"

using namespace SCT::LogColors::Operators;

#ifdef USE_SCT_LC
	namespace LC = SCT::LogColors;
#endif

#ifdef USE_SCT_LOGCOLORS
	namespace LogColors = SCT::LogColors;
#endif
