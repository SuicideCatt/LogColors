inline const short int SCT::LogColors::fg(Terminal::Color color, bool bright)
{
	return !bright ? (short int)color + 30 : (short int)color + 90;
}

inline const short int SCT::LogColors::bg(Terminal::Color color, bool bright)
{
	return !bright ? (short int)color + 40 : (short int)color + 100;
}

inline const std::string SCT::LogColors::color()
	{ return "\033[0m"; }

inline void SCT::LogColors::DarkSide::color(std::stringstream& ss) 
	{ ss << 'm'; }