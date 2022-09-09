#pragma once

#include <ostream>
#include <type_traits>
#include <concepts>

namespace SCT::LogColors::Concepts
{
	template<typename TypeA, typename TypeB>
	concept IsSomeMode = std::same_as<std::remove_reference_t<TypeA>, TypeB>;

	template<typename Type>
	concept IsColorEd = IsSomeMode<Type, Mode::ColorEd>;

	template<typename Type>
	concept IsPrint = IsSomeMode<Type, Mode::Print>;
	
	template<typename Type>
	concept IsMode = IsColorEd<Type> || IsPrint<Type>;

	template<typename Type>
	concept IsFG_16 = std::same_as<Type, fg::_16>;

	template<typename Type>
	concept IsBG_16 = std::same_as<Type, bg::_16>;

	template<typename Type>
	concept IsFG_256 = std::same_as<Type, fg::_256>;

	template<typename Type>
	concept IsBG_256 = std::same_as<Type, bg::_256>;

	template<typename Type>
	concept Is_16 = IsFG_16<Type> || IsBG_16<Type>;

	template<typename Type>
	concept Is_256 = IsFG_256<Type> || IsBG_256<Type>;

	template<typename Type>
	concept IsForm = std::same_as<Type, form::v>;

	template<typename Type>
	concept IsFG = IsFG_16<Type> || IsFG_256<Type>;

	template<typename Type>
	concept IsBG = IsBG_16<Type> || IsBG_256<Type>;

	template<typename Type>
	concept IsColor = IsFG<Type> || IsBG<Type>;

	template<typename Type>
	concept IsReset = std::same_as<Type, Terminal::Reset::Reset>
		|| std::same_as<Type, Terminal::Reset::Delete>;

	template<typename Type>
	concept IsColorOrForm = IsColor<Type> || IsForm<Type>;

	template<typename Type>
	concept IsNotColorOrFormOrReset = !(Concepts::IsColorOrForm<Type>
		|| Concepts::IsReset<Type>);
}

namespace SCT::LogColors::Operators
{
	template<Concepts::IsColorEd CurMode, Concepts::IsColor Type>
	inline CurMode operator <<(CurMode&& col, const Type& p)
	{
		if constexpr (Concepts::Is_16<Type>)
			col.mode[Type::id] = std::remove_reference_t<CurMode>::_16;
		else if constexpr (Concepts::Is_256<Type>)
			col.mode[Type::id] = std::remove_reference_t<CurMode>::_256;

		col.color[Type::id] = p;

		return col;
	}

	template<Concepts::IsColorEd CurMode>
	inline CurMode operator <<(CurMode&& col, const form::v& p)
	{
		if (p != form::reset)
		{
			auto& v = col.form[p];
			v = !v;
			col.formClear = false;
		}
		else
		{
			std::fill_n(col.form, 9, false);
			col.formClear = true;
		}

		return col;
	}

	template<Concepts::IsMode CurMode>
	inline CurMode operator <<(CurMode&& col, const Terminal::Reset::Reset& p)
	{
		col.reset();
		return col;
	}

	inline std::ostream&
		operator <<(std::ostream& out, const Terminal::Reset::Delete& p)
	{
		return out << "\033[0m";
	}

	template<Concepts::IsMode CurMode>
	inline std::ostream& operator <<(CurMode&& col,
		const Terminal::Reset::Delete& p)
	{
		return col.out << p;
	}

	template<Concepts::IsColorOrForm Type>
	inline Mode::ColorEd operator <<(std::ostream& out, const Type& p)
	{
		Mode::ColorEd col{out};
		return col << p;
	}

	template<Concepts::IsPrint CurMode, Concepts::IsNotColorOrFormOrReset Type>
	inline CurMode operator <<(CurMode&& col, const Type& value)
	{
		col.out << value;
		return col;
	}

	template<Concepts::IsColorEd CurMode,
		Concepts::IsNotColorOrFormOrReset Type>
	inline std::conditional_t<std::is_lvalue_reference_v<CurMode>, 
			Mode::Print&, Mode::Print> 
		operator <<(CurMode&& col, const Type& value)
	{
		col.out << "\033[0;";

		for (short int i = 0; i < 9 && !col.formClear; i++)
		{
			if (col.form[i] && i != 5)
			{
				col.out << i + 1 << ';';
			}
		}

		col.invert();

		if (col.mode[0] == std::remove_reference_t<CurMode>::_256)
			col.out << "38;5;";
		col.out << col.color[0] << ';';

		if (col.mode[1] == std::remove_reference_t<CurMode>::_256)
			col.out << "48;5;";
		col.out << col.color[1] << 'm';

		col.out << value;

		col.invert();

		return reinterpret_cast<Mode::Print&>(col);
	}

	template<Concepts::IsPrint CurMode, Concepts::IsColorOrForm Type>
	inline std::conditional_t<std::is_lvalue_reference_v<CurMode>, 
			Mode::ColorEd&, Mode::ColorEd> 
		operator <<(CurMode&& col, const Type& p)
	{
		return reinterpret_cast<Mode::ColorEd&>(col) << p;
	}
}