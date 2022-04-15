template<typename... Args>
const std::string SCT::LogColors::color(Args... args)
{
	std::stringstream ss;
	
	ss << "\033[0";
	DarkSide::color(ss, args...);

	return ss.str();
}

template<typename First, typename... Args>
inline void SCT::LogColors::DarkSide::color
	(std::stringstream& ss, First first, Args... args)
{
	ss << ';' << (int)first;
	DarkSide::color(ss, args...);
}

