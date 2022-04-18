#pragma once

#include "LogColors.hpp"

#define GEN_TCOL(t, v) \
	SCT::LogColors::t(SCT::LogColors::Color::v)

#define GEN_TFG(v) GEN_TCOL(fg, v)
#define GEN_TBG(v) GEN_TCOL(bg, v)

#define GEN_TFORM(v) SCT::LogColors::Formation::v

// Foreground colors
#define TFG_BLACK			GEN_TFG(black)
#define TFG_RED				GEN_TFG(red)
#define TFG_GREEN			GEN_TFG(green)
#define TFG_YELLOW			GEN_TFG(yellow)
#define TFG_BLUE			GEN_TFG(blue)
#define TFG_MAGENTA			GEN_TFG(magenta)
#define TFG_CYAN			GEN_TFG(cyan)
#define TFG_LigftGRAY		GEN_TFG(ligftGray)
#define TFG_DarkGRAY		GEN_TFG(darkGray)
#define TFG_LigftRED		GEN_TFG(lightRed)
#define TFG_LigftGREEN		GEN_TFG(lightGreen)
#define TFG_LigftYELLOW		GEN_TFG(lightYellow)
#define TFG_LigftBLUE		GEN_TFG(lightBlue)
#define TFG_LigftMAGENTA	GEN_TFG(lightMagenta)
#define TFG_LigftCYAN		GEN_TFG(lightCyan)
#define TFG_WHITE			GEN_TFG(white)

// Background colors
#define TBG_BLACK			GEN_TBG(black)
#define TBG_RED				GEN_TBG(red)
#define TBG_GREEN			GEN_TBG(green)
#define TBG_YELLOW			GEN_TBG(yellow)
#define TBG_BLUE			GEN_TBG(blue)
#define TBG_MAGENTA			GEN_TBG(magenta)
#define TBG_CYAN			GEN_TBG(cyan)
#define TBG_LigftGRAY		GEN_TBG(ligftGray)
#define TBG_DarkGRAY		GEN_TBG(darkGray)
#define TBG_LigftRED		GEN_TBG(lightRed)
#define TBG_LigftGREEN		GEN_TBG(lightGreen)
#define TBG_LigftYELLOW		GEN_TBG(lightYellow)
#define TBG_LigftBLUE		GEN_TBG(lightBlue)
#define TBG_LigftMAGENTA	GEN_TBG(lightMagenta)
#define TBG_LigftCYAN		GEN_TBG(lightCyan)
#define TBG_WHITE			GEN_TBG(white)

// Text formation
#define TFORM_BOLD			GEN_TFORM(bold)
#define TFORM_DIM			GEN_TFORM(dim)
#define TFORM_ITALIC		GEN_TFORM(italic)
#define TFORM_UNDERLINE		GEN_TFORM(underline)
#define TFORM_BLINK			GEN_TFORM(blink)
#define TFORM_REVERSION		GEN_TFORM(reversion)
#define TFORM_CONCEAL		GEN_TFORM(conceal)
#define TFORM_STRIKETHROUGH	GEN_TFORM(strikethrough)