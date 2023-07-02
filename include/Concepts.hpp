#pragma once

#include "Mode.hpp"
#include "Terminal.hpp"

#include <concepts>

namespace SCT::LogColors::Concepts
{
	template<typename A, typename B>
	concept IsSameMode = std::same_as<std::remove_reference_t<A>, B>;

	template<typename Type>
	concept IsColored = IsSameMode<Type, Mode::Colored>;

	template<typename Type>
	concept IsPrint = IsSameMode<Type, Mode::Print>;

	template<typename Type>
	concept IsMode = IsColored<Type> || IsPrint<Type>;

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
	concept IsForm = std::same_as<Type, form::t>;

	template<typename Type>
	concept IsFG = IsFG_16<Type> || IsFG_256<Type>;

	template<typename Type>
	concept IsBG = IsBG_16<Type> || IsBG_256<Type>;

	template<typename Type>
	concept IsColor = IsFG<Type> || IsBG<Type>;

	template<typename Type>
	concept IsReset =
		std::same_as<Type, Reset> || std::same_as<Type, Disable>;

	template<typename Type>
	concept IsColorOrForm = IsColor<Type> || IsForm<Type>;

	template<typename Type>
	concept IsNotColorOrFormOrReset =
		!(Concepts::IsColorOrForm<Type> || Concepts::IsReset<Type>);
}
