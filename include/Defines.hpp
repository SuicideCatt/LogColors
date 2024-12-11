#pragma once

#ifdef _MSC_VER
	#define SCT_LC_INL [[msvc::forceinline]] inline
#else
	#define SCT_LC_INL [[gnu::always_inline]] inline
#endif

