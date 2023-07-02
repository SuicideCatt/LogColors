#pragma once

#include "../Concepts.hpp"

#include <ostream>

namespace SCT::LogColors::Operators
{
	template<Concepts::IsColored CurrMode, Concepts::IsColor Type>
	SCT_LC_INL CurrMode operator<<(CurrMode&& m, const Type& col)
	{
		if constexpr (Concepts::Is_16<Type>)
			m.mode[Type::id] = std::remove_reference_t<CurrMode>::_16;
		else if constexpr (Concepts::Is_256<Type>)
			m.mode[Type::id] = std::remove_reference_t<CurrMode>::_256;

		m.color[Type::id] = col;

		return m;
	}

	template<Concepts::IsColored CurrMode>
	SCT_LC_INL CurrMode operator<<(CurrMode&& m, const form::t& f)
	{
		if (f == form::reset)
		{
			m.reset_formation();
		}
		else
		{
			auto& v = m.form[f];
			v = !v;
			m.form_clear = false;
		}

		return m;
	}

	template<Concepts::IsMode CurrMode>
	SCT_LC_INL CurrMode operator<<(CurrMode&& m, const Reset& r)
	{
		m.reset();
		return m;
	}

	SCT_LC_INL std::ostream& operator<<(std::ostream& out, const Disable& d)
		{ return out << "\033[0m"; }

	template<Concepts::IsMode CurrMode>
	SCT_LC_INL std::ostream& operator<<(CurrMode&& m, const Disable& p)
		{ return m.out << "\033[0m"; }

	template<Concepts::IsColorOrForm Type>
	SCT_LC_INL Mode::Colored operator<<(std::ostream& out, const Type& p)
	{
		Mode::Colored m(out);
		return m << p;
	}

	template<Concepts::IsPrint CurrMode, Concepts::IsNotColorOrFormOrReset Type>
	SCT_LC_INL CurrMode operator<<(CurrMode&& m, const Type& value)
	{
		m.out << value;
		return m;
	}

	template<Concepts::IsColored CurrMode,
			 Concepts::IsNotColorOrFormOrReset Type>
	SCT_LC_INL auto operator<<(CurrMode&& m, const Type& value)
		-> std::conditional_t<std::is_lvalue_reference_v<CurrMode>,
							  Mode::Print&, Mode::Print>
	{
		m.out << "\033[0;";

		for (uint16_t i = 0; i < 9 && !m.form_clear; ++i)
		{
			if (i != 5 && m.form[i])
				m.out << i + 1 << ';';
		}

		m.invert();

		if (m.mode[0] == std::remove_reference_t<CurrMode>::_256)
			m.out << "38;5;";
		m.out << m.color[0] << ';';

		if (m.mode[1] == std::remove_reference_t<CurrMode>::_256)
			m.out << "48;5;";
		m.out << m.color[1] << 'm';

		m.out << value;

		m.invert();

		return reinterpret_cast<Mode::Print&>(m);
	}

	template<Concepts::IsPrint CurrMode, Concepts::IsColorOrForm Type>
	SCT_LC_INL auto operator<<(CurrMode&& m, const Type& p)
		-> std::conditional_t<std::is_lvalue_reference_v<CurrMode>,
							  Mode::Colored&, Mode::Colored>
		{ return reinterpret_cast<Mode::Colored&>(m) << p; }
}
