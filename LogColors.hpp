#pragma once

#include <string>
#include <sstream>

namespace SCT::LogColors
{
	namespace Terminal
	{
		enum class Color : short int
		{
			Black = 0,		Red,
			Green,			Yellow,
			Blue,			Magenta,
			Cyan,			White
		};

		enum class Formation : short int
		{
			Bold = 1, 		SemiBright,
			Italic,			Underline,
			Blink,			Reversion = 7,
			Conceal,		Strikethrough
		};
	}

	/**
	 * @brief 
	 * 
	 * @param color Color enum (0-7)
	 * @param bright Is bright?
	 * @return Foreground Color for Linux terminal
	 */
	inline const short int fg(Terminal::Color color, bool bright = false);
	/**
	 * @brief 
	 * 
	 * @param color Color enum (0-7)
	 * @param bright Is bright?
	 * @return Background Color for Linux terminal
	 */
	inline const short int bg(Terminal::Color color, bool bright = false);

	/**
	 * @brief Color and Formating
	 * 
	 * @tparam Args list type
	 * @param args list for colors and formations on text
	 * @return Configurate for change color and formation
	 */
	template<typename... Args>
	const std::string color(Args... args);

	/**
	 * @brief Reset to default Color and Formating
	 * 
	 * @return Default configuration
	 */
	inline const std::string color();
	
	namespace DarkSide
	{
		template<typename First, typename... Args>
		inline void color(std::stringstream& ss, First first, Args... args);
		
		inline void color(std::stringstream& ss);
	}
	
	using namespace Terminal;
}

#ifdef USE_SCT_LC
namespace LC = SCT::LogColors;
#elif defined(USE_SCT_LOGCOLORS)
namespace LogColors = SCT::LogColors;
#endif

#include "ipp/LogColors.ipp"
#include "tpp/LogColors.tpp"