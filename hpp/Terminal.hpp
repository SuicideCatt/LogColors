#pragma once

namespace SCT::LogColors::Terminal
{
	namespace Templates
	{
		template<short int Color, short int Id>
		struct _16_t
		{
			enum _16 : short int
			{
				black = Color,				red,
				green,						yellow,
				blue,						magenta,
				cyan,						ligftGray,
				
				darkGray = Color + 60,		lightRed,
				lightGreen,					lightYellow,
				lightBlue,					lightMagenta,
				lightCyan,					white,
				
				reset = Color + 9,

				id = Id
			};
		};

		template<unsigned char Id>
		struct _256_t
		{
			unsigned char color = 0;

			static constexpr unsigned char id = Id;

			inline operator short int() const
				{ return color; }
		};

		template<short int Color, short int Id>
		struct Colors : public _16_t<Color, Id>
		{
			using _256 = _256_t<Id>;
		};
	}

	using FGColors = Templates::Colors<30, 0>;
	using BGColors = Templates::Colors<40, 1>;
	
	namespace Formations
	{
		enum v : char
		{
			bold = 0, 		dim,
			italic,			underline,
			blink,			invert,
			reversion,		conceal,
			strikethrough,
			
			reset = 9
		};
	}

	namespace Reset
	{
		enum Reset
		{
			reset
		};

		enum Delete
		{
			off
		};
	}
}
