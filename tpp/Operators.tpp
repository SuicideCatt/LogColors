#pragma once

#include <ostream>
#include <type_traits>

#define enableIf(value) std::enable_if_t<value, bool> = true

#define isSame(typeA, typeB) std::is_same_v<typeA, typeB>

#define isColorEd(type) \
	isSame(std::remove_reference_t<type>, Mode::ColorEd)
#define isPrint(type) \
	isSame(std::remove_reference_t<type>, Mode::Print)

#define enableIfIsColorEd(type) \
	enableIf(isColorEd(type))

#define enableIfIsPrint(type) \
	enableIf(isPrint(type))

#define enableIfIsMode(type) \
	enableIf(isColorEd(type) || isPrint(type))

#define isForm(type)	isSame(type, form)
#define isFG(type)		isSame(type, fg)
#define isBG(type)		isSame(type, bg)
#define isReset(type) \
	isSame(type, Terminal::Reset) || isSame(type, Terminal::Delete)

#define isColor(type)		isFG(type)		|| isBG(type)
#define isColorOrForm(type)	isColor(type)	|| isForm(type)

#define enableIfIsColor(type) \
	enableIf(isColor(type))

#define enableIfIsColorOrForm(type) \
	enableIf(isColorOrForm(type))

#define enableIfIsNotColorOrForm(type) \
	enableIf(!(isColorOrForm(type)))

#define enableIfIsNotColorOrFormOrReset(type) \
	enableIf(!(isColorOrForm(type) || isReset(type)))

#define CastShortInt(value) static_cast<short int>(value)

namespace SCT::LogColors::Operators
{
	template<typename CurMode, typename Type, 
		enableIfIsColorEd(CurMode), enableIfIsColor(Type)>
	inline CurMode operator <<(CurMode&& col, Type p)
	{
		col.g[Type::id] = p;
		return col;
	}

	template<typename CurMode, enableIfIsColorEd(CurMode)>
	inline CurMode operator <<(CurMode&& col, form p)
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

	template<typename CurMode, enableIfIsMode(CurMode)>
	inline CurMode operator <<(CurMode&& col, Terminal::Reset p)
	{
		col.reset();
		return col;
	}

	template<typename CurMode, enableIfIsMode(CurMode)>
	inline std::ostream& operator <<(CurMode&& col, Terminal::Delete p)
	{
		return col.out << "\033[0m";
	}

	template<typename Type, enableIfIsColorOrForm(Type)>
	inline Mode::ColorEd operator <<(std::ostream& out, Type p)
	{
		Mode::ColorEd col{out};
		return col << p;
	}

	template<typename CurMode, typename Type, 
		enableIfIsPrint(CurMode), enableIfIsNotColorOrForm(Type)>
	inline CurMode operator <<(CurMode&& col, Type value)
	{
		col.out << value;
		return col;
	}

	template<typename CurMode, typename Type, 
		enableIfIsColorEd(CurMode), enableIfIsNotColorOrFormOrReset(Type)>
	inline std::conditional_t<std::is_lvalue_reference_v<CurMode>, 
			Mode::Print&, Mode::Print> 
		operator <<(CurMode&& col, Type value)
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

		col.out << col.g[0] << ';'
				<< col.g[1] << 'm'
				<< value;

		col.invert();

		return reinterpret_cast<Mode::Print&>(col);
	}

	template<typename CurMode, typename Type, 
		enableIfIsPrint(CurMode), enableIfIsColorOrForm(Type)>
	inline std::conditional_t<std::is_lvalue_reference_v<CurMode>, 
			Mode::ColorEd&, Mode::ColorEd> 
		operator <<(CurMode&& col, Type p)
	{
		return reinterpret_cast<Mode::ColorEd&>(col) << p;
	}
}

#undef enableIf
#undef isSame

#undef isColorEd
#undef isPrint

#undef enableIfIsColorEd
#undef enableIfIsPrint
#undef enableIfIsMode

#undef isForm
#undef isFG
#undef isBG

#undef isReset

#undef isColor
#undef isColorOrForm

#undef enableIfIsColor
#undef enableIfIsColorOrForm
#undef enableIfIsNotColorOrForm
#undef enableIfIsNotColorOrFormOrReset