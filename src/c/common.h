// 2017 Thomas Hunsaker @thunsaker

#pragma once

#include <pebble.h>

#ifdef PBL_SDK_3
	#define STATUS_BAR_OFFSET 0
#else
	#define STATUS_BAR_OFFSET 12
#endif
