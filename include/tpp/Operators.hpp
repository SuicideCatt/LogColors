#pragma once

#include "../Concepts.hpp"

namespace SCT::LogColors::Operators
{
	template<Concepts::IsModeConfig CurrMode, Concepts::IsFG Type>
	SCT_LC_INL CurrMode operator<<(CurrMode&& m, Type&& fg)
	{
		m.fg_color = fg;
		return m;
	}

	template<Concepts::IsModeConfig CurrMode, Concepts::IsBG Type>
	SCT_LC_INL CurrMode operator<<(CurrMode&& m, Type&& bg)
	{
		m.bg_color = bg;
		return m;
	}

	template<Concepts::IsModeConfig CurrMode>
	SCT_LC_INL CurrMode operator<<(CurrMode&& m, form f)
	{
		if (f == form::reset)
		{
			m.reset_formation();
		}
		else
		{
			auto& v = m.form[static_cast<uint8_t>(f)];
			v = !v;
			m.form_clear = false;
		}

		return m;
	}

	template<Concepts::IsMode CurrMode>
	SCT_LC_INL auto operator<<(CurrMode&& m, DarkSide::Reset r)
		-> std::conditional_t<std::is_lvalue_reference_v<CurrMode>,
							  Mode::Config&, Mode::Config>
	{
		m.reset();
		m.print_reset();

		return reinterpret_cast<Mode::Config&>(m);
	}

	SCT_LC_INL std::ostream& operator<<(std::ostream& out, DarkSide::Disable d)
		{ return out.write("\033[0m", 4); }

	template<Concepts::IsMode CurrMode>
	SCT_LC_INL std::ostream& operator<<(CurrMode&& m, DarkSide::Disable p)
		{ return m.out << p; }

	template<Concepts::IsColorOrForm Type>
	SCT_LC_INL Mode::Config operator<<(std::ostream& out, Type&& p)
	{
		Mode::Config m(out);
		return m << p;
	}

	template<Concepts::IsModePrint CurrMode,
			 Concepts::IsNotColorOrFormOrReset Type>
	SCT_LC_INL CurrMode operator<<(CurrMode&& m, const Type& value)
	{
		m.out << value;
		return m;
	}

	template<Concepts::IsModeConfig CurrMode,
			 Concepts::IsNotColorOrFormOrReset Type>
	SCT_LC_INL auto operator<<(CurrMode&& m, const Type& value)
		-> std::conditional_t<std::is_lvalue_reference_v<CurrMode>,
							  Mode::Printing&, Mode::Printing>
	{
		auto& p = reinterpret_cast<Mode::Printing&>(m);
		p.print_formation();
		return p << value;
	}

	template<Concepts::IsModePrint CurrMode, Concepts::IsColorOrForm Type>
	SCT_LC_INL auto operator<<(CurrMode&& m, Type&& p)
		-> std::conditional_t<std::is_lvalue_reference_v<CurrMode>,
							  Mode::Config&, Mode::Config>
		{ return reinterpret_cast<Mode::Config&>(m) << p; }
}
