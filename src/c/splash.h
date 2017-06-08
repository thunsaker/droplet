// 2017 Thomas Hunsaker @thunsaker

#pragma once

#include <pebble.h>

void splash_show(bool icon, char message[128]);
void splash_hide(void);
void splash_deinit(void);
