// 2017 Thomas Hunsaker @thunsaker

#include <pebble.h>
#include "src/c/splash.h"

void handle_init(void) {
  	splash_show(true, "");
}

void handle_deinit(void) {
}

int main(void) {
  	handle_init();
  	app_event_loop();
  	handle_deinit();
}
