#pragma once

#include "LogColors.hpp"

#define GEN_TCOL(t, v) \
	SCT::LogColors::t(SCT::LogColors::Color::v)

#define GEN_TFG(v) GEN_TCOL(fg, v)
#define GEN_TBG(v) GEN_TCOL(bg, v)

#define GEN_TBCOL(t, v) \
	SCT::LogColors::t(SCT::LogColors::Color::v, true)

#define GEN_TBFG(v) GEN_TBCOL(fg, v)
#define GEN_TBBG(v) GEN_TBCOL(bg, v)

#define GEN_TFORM(v) SCT::LogColors::Formation::v

// Foreground colors
#define TFG_BLACK	GEN_TFG(Black)
#define TFG_RED		GEN_TFG(Red)
#define TFG_GREEN	GEN_TFG(Green)
#define TFG_YELLOW	GEN_TFG(Yellow)
#define TFG_BLUE	GEN_TFG(Blue)
#define TFG_MAGENTA	GEN_TFG(Magenta)
#define TFG_CYAN	GEN_TFG(Cyan)
#define TFG_WHITE	GEN_TFG(White)

// Background colors
#define TBG_BLACK	GEN_TBG(Black)
#define TBG_RED		GEN_TBG(Red)
#define TBG_GREEN	GEN_TBG(Green)
#define TBG_YELLOW	GEN_TBG(Yellow)
#define TBG_BLUE	GEN_TBG(Blue)
#define TBG_MAGENTA	GEN_TBG(Magenta)
#define TBG_CYAN	GEN_TBG(Cyan)
#define TBG_WHITE	GEN_TBG(White)

// Bright foreground colors
#define TFG_BrightBLACK		GEN_TBFG(Black)
#define TFG_BrightRED		GEN_TBFG(Red)
#define TFG_BrightGREEN		GEN_TBFG(Green)
#define TFG_BrightYELLOW	GEN_TBFG(Yellow)
#define TFG_BrightBLUE		GEN_TBFG(Blue)
#define TFG_BrightMAGENTA	GEN_TBFG(Magenta)
#define TFG_BrightCYAN		GEN_TBFG(Cyan)
#define TFG_BrightWHITE		GEN_TBFG(White)

// Bright background colors
#define TBG_BrightBLACK		GEN_TBBG(Black)
#define TBG_BrightRED		GEN_TBBG(Red)
#define TBG_BrightGREEN		GEN_TBBG(Green)
#define TBG_BrightYELLOW	GEN_TBBG(Yellow)
#define TBG_BrightBLUE		GEN_TBBG(Blue)
#define TBG_BrightMAGENTA	GEN_TBBG(Magenta)
#define TBG_BrightCYAN		GEN_TBBG(Cyan)
#define TBG_BrightWHITE		GEN_TBBG(White)

// Text formation
#define TFORM_BOLD			GEN_TFORM(Bold)
#define TFORM_SEMI_BRIGHT	GEN_TFORM(SemiBright)
#define TFORM_ITALIC		GEN_TFORM(Italic)
#define TFORM_UNDERLINE		GEN_TFORM(Underline)
#define TFORM_BLINK			GEN_TFORM(Blink)
#define TFORM_REVERSION		GEN_TFORM(Reversion)
#define TFORM_CONCEAL		GEN_TFORM(Conceal)
#define TFORM_STRIKETHROUGH	GEN_TFORM(Strikethrough)