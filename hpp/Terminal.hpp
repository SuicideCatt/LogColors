#pragma once

namespace SCT::LogColors::Terminal
{
	namespace FGColors
	{
		enum v : short int
		{
			black = 30,		red,
			green,			yellow,
			blue,			magenta,
			cyan,			ligftGray,
			
			darkGray = 90,	lightRed,
			lightGreen,		lightYellow,
			lightBlue,		lightMagenta,
			lightCyan,		white,
			
			reset = 39,

			id = 0
		};
	}

	namespace BGColors
	{
		enum v : short int
		{
			black = 40,		red,
			green,			yellow,
			blue,			magenta,
			cyan,			ligftGray,
			
			darkGray = 100,	lightRed,
			lightGreen,		lightYellow,
			lightBlue,		lightMagenta,
			lightCyan,		white,
			
			reset = 49,

			id = 1
		};
	}
	
	namespace Formations
	{
		enum v : short int
		{
			bold = 0, 		dim,
			italic,			underline,
			blink,			invert,
			reversion,		conceal,
			strikethrough,
			
			reset = 9
		};
	}

	enum Reset
	{
		reset
	};

	enum Delete
	{
		off
	};
}