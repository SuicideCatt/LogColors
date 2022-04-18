#pragma once

#include "LogColors.hpp"

#define GEN_TCOL(t, v) \
	SCT::LogColors::t(SCT::LogColors::Color::v)

#define GEN_TFG(v) GEN_TCOL(fg, v)
#define GEN_TBG(v) GEN_TCOL(bg, v)

#define GEN_TFORM(v) SCT::LogColors::Formation::v

// Foreground colors
#define TFG_BLACK			GEN_TFG(Black)
#define TFG_RED				GEN_TFG(Red)
#define TFG_GREEN			GEN_TFG(Green)
#define TFG_YELLOW			GEN_TFG(Yellow)
#define TFG_BLUE			GEN_TFG(Blue)
#define TFG_MAGENTA			GEN_TFG(Magenta)
#define TFG_CYAN			GEN_TFG(Cyan)
#define TFG_LigftGRAY		GEN_TFG(LigftGray)
#define TFG_DarkGRAY		GEN_TFG(DarkGray)
#define TFG_LigftRED		GEN_TFG(LightRed)
#define TFG_LigftGREEN		GEN_TFG(LightGreen)
#define TFG_LigftYELLOW		GEN_TFG(LightYellow)
#define TFG_LigftBLUE		GEN_TFG(LightBlue)
#define TFG_LigftMAGENTA	GEN_TFG(LightMagenta)
#define TFG_LigftCYAN		GEN_TFG(LightCyan)
#define TFG_WHITE			GEN_TFG(White)

// Background colors
#define TBG_BLACK			GEN_TBG(Black)
#define TBG_RED				GEN_TBG(Red)
#define TBG_GREEN			GEN_TBG(Green)
#define TBG_YELLOW			GEN_TBG(Yellow)
#define TBG_BLUE			GEN_TBG(Blue)
#define TBG_MAGENTA			GEN_TBG(Magenta)
#define TBG_CYAN			GEN_TBG(Cyan)
#define TBG_LigftGRAY		GEN_TBG(LigftGray)
#define TBG_DarkGRAY		GEN_TBG(DarkGray)
#define TBG_LigftRED		GEN_TBG(LightRed)
#define TBG_LigftGREEN		GEN_TBG(LightGreen)
#define TBG_LigftYELLOW		GEN_TBG(LightYellow)
#define TBG_LigftBLUE		GEN_TBG(LightBlue)
#define TBG_LigftMAGENTA	GEN_TBG(LightMagenta)
#define TBG_LigftCYAN		GEN_TBG(LightCyan)
#define TBG_WHITE			GEN_TBG(White)

// Text formation
#define TFORM_BOLD			GEN_TFORM(Bold)
#define TFORM_DIM			GEN_TFORM(Dim)
#define TFORM_ITALIC		GEN_TFORM(Italic)
#define TFORM_UNDERLINE		GEN_TFORM(Underline)
#define TFORM_BLINK			GEN_TFORM(Blink)
#define TFORM_REVERSION		GEN_TFORM(Reversion)
#define TFORM_CONCEAL		GEN_TFORM(Conceal)
#define TFORM_STRIKETHROUGH	GEN_TFORM(Strikethrough)