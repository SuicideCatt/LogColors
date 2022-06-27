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

#define isFG_16(type)	isSame(type, fg::_16)
#define isBG_16(type)	isSame(type, bg::_16)

#define isFG_256(type)	isSame(type, fg::_256)
#define isBG_256(type)	isSame(type, bg::_256)

#define is_16(type)		isFG_16(type) || isBG_16(type)
#define is_256(type)	isFG_256(type) || isBG_256(type)

#define isForm(type)	isSame(type, form::v)
#define isFG(type)		isFG_16(type) || isFG_256(type)
#define isBG(type)		isBG_16(type) || isBG_256(type)

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

namespace SCT::LogColors::Operators
{
	template<typename CurMode, typename Type, 
		enableIfIsColorEd(CurMode), enableIfIsColor(Type)>
	inline CurMode operator <<(CurMode&& col, const Type& p)
	{
		if constexpr (is_16(Type))
			col.mode[Type::id] = std::remove_reference_t<CurMode>::_16;
		else if constexpr (is_256(Type))
			col.mode[Type::id] = std::remove_reference_t<CurMode>::_256;

		col.color[Type::id] = p;

		return col;
	}

	template<typename CurMode, enableIfIsColorEd(CurMode)>
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

	template<typename CurMode, enableIfIsMode(CurMode)>
	inline CurMode operator <<(CurMode&& col, const Terminal::Reset& p)
	{
		col.reset();
		return col;
	}

	inline std::ostream&
		operator <<(std::ostream& out, const Terminal::Delete& p)
	{
		return out << "\033[0m";
	}

	template<typename CurMode, enableIfIsMode(CurMode)>
	inline std::ostream& operator <<(CurMode&& col, const Terminal::Delete& p)
	{
		return col.out << p;
	}

	template<typename Type, enableIfIsColorOrForm(Type)>
	inline Mode::ColorEd operator <<(std::ostream& out, const Type& p)
	{
		Mode::ColorEd col{out};
		return col << p;
	}

	template<typename CurMode, typename Type, 
		enableIfIsPrint(CurMode), enableIfIsNotColorOrForm(Type)>
	inline CurMode operator <<(CurMode&& col, const Type& value)
	{
		col.out << value;
		return col;
	}

	template<typename CurMode, typename Type, 
		enableIfIsColorEd(CurMode), enableIfIsNotColorOrFormOrReset(Type)>
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

	template<typename CurMode, typename Type, 
		enableIfIsPrint(CurMode), enableIfIsColorOrForm(Type)>
	inline std::conditional_t<std::is_lvalue_reference_v<CurMode>, 
			Mode::ColorEd&, Mode::ColorEd> 
		operator <<(CurMode&& col, Type p)
	{
		return reinterpret_cast<Mode::ColorEd&>(col) << p;
	}
}

#undef enableIfIsNotColorOrFormOrReset
#undef enableIfIsNotColorOrForm
#undef enableIfIsColorOrForm
#undef enableIfIsColor
#undef isColorOrForm

#undef isColor
#undef isReset

#undef isBG
#undef isFG
#undef isForm

#undef is_256
#undef is_16

#undef isBG_256
#undef isFG_256
#undef isBG_16
#undef isFG_16

#undef enableIfIsMode
#undef enableIfIsPrint
#undef enableIfIsColorEd

#undef isPrint
#undef isColorEd

#undef isSame
#undef enableIf