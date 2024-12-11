#pragma once

#include "Mode.hpp"

#include <concepts>

namespace SCT::LogColors::Concepts
{
	template<typename A, typename B>
	concept IsSameRmRef = std::same_as<std::remove_reference_t<A>, B>;

	template<typename Type>
	concept IsModeConfig = IsSameRmRef<Type, Mode::Config>;

	template<typename Type>
	concept IsModePrint = IsSameRmRef<Type, Mode::Printing>;

	template<typename Type>
	concept IsMode = IsModeConfig<Type> || IsModePrint<Type>;

	template<typename Type>
	concept IsFG_16 = IsSameRmRef<Type, fg::c16>;

	template<typename Type>
	concept IsBG_16 = IsSameRmRef<Type, bg::c16>;

	template<typename Type>
	concept IsFG_256 = IsSameRmRef<Type, fg::c256>;

	template<typename Type>
	concept IsBG_256 = IsSameRmRef<Type, bg::c256>;

	template<typename Type>
	concept IsForm = IsSameRmRef<Type, form>;

	template<typename Type>
	concept IsFG = IsFG_16<Type> || IsFG_256<Type>;

	template<typename Type>
	concept IsBG = IsBG_16<Type> || IsBG_256<Type>;

	template<typename Type>
	concept IsColor = IsFG<Type> || IsBG<Type>;

	template<typename Type>
	concept IsColorOrForm = IsColor<Type> || IsForm<Type>;

	template<typename Type>
	concept IsReset = IsSameRmRef<Type, DarkSide::Reset>
					  || IsSameRmRef<Type, DarkSide::Disable>;

	template<typename Type>
	concept IsNotColorOrFormOrReset =
		!(Concepts::IsColorOrForm<Type> || Concepts::IsReset<Type>);
}
