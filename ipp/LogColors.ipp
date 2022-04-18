inline const short int
	SCT::LogColors::fg(Terminal::Color color)
	{ return DarkSide::getColor(color, 0); }

inline const short int
	SCT::LogColors::bg(Terminal::Color color)
	{ return DarkSide::getColor(color, 10); }

inline const std::string SCT::LogColors::color()
	{ return "\033[0m"; }

inline std::ostream&
	SCT::LogColors::Operators::operator <<(std::ostream& out,
		SCT::LogColors::Terminal::Reset r)
	{ return out << "\033[0m"; }

inline void SCT::LogColors::DarkSide::color(std::stringstream& ss)
	{ ss << 'm'; }

inline const short int 
	SCT::LogColors::DarkSide::getColor(Terminal::Color color, short int shift)
	{ return (short int)color + shift; }