#pragma once

#ifndef SCT_INL
	// NOTE: If is not work on window... POHUI
	#define SCT_LC_INL [[gnu::always_inline]] inline
#else
	#define SCT_LC_INL SCT_INL
#endif
