#include <pebble.h>

Window *my_window;
TextLayer *text_layer;
BitmapLayer *bitmap_layer;

static int SCREEN_HEIGHT;
static int SCREEN_WIDTH;

void handle_init(void) {
  	my_window = window_create();
		
	Layer *window_layer = window_get_root_layer(my_window);
	#ifdef PBL_COLOR
		window_set_background_color(my_window, GColorRichBrilliantLavender);
	#else
		window_set_background_color(my_window, GColorBlack);
	#endif
	
	GRect bounds = layer_get_frame(window_layer);
	SCREEN_HEIGHT = bounds.size.h;
	SCREEN_WIDTH = bounds.size.w;
	
	bitmap_layer = bitmap_layer_create(GRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT-40));
	bitmap_layer_set_alignment(bitmap_layer, GAlignCenter);
	bitmap_layer_set_compositing_mode(bitmap_layer, GCompOpSet);
	
	bitmap_layer_set_bitmap(bitmap_layer, gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DROP_LARGE));
	layer_add_child(window_layer, bitmap_layer_get_layer(bitmap_layer));
	text_layer = text_layer_create(GRect(0, SCREEN_HEIGHT-60, SCREEN_WIDTH, 40));
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
	#ifdef PBL_COLOR
		text_layer_set_text_color(text_layer, GColorOxfordBlue);
		text_layer_set_background_color(text_layer, GColorRichBrilliantLavender);
	#else
		text_layer_set_text_color(text_layer, GColorWhite);
		text_layer_set_background_color(text_layer, GColorBlack);
	#endif
	text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
	
	text_layer_set_text(text_layer, "Droplet");
	layer_add_child(window_layer, text_layer_get_layer(text_layer));
	
	
  	window_stack_push(my_window, true);
}

void handle_deinit(void) {
  	text_layer_destroy(text_layer);
  	window_destroy(my_window);
}

int main(void) {
  	handle_init();
  	app_event_loop();
  	handle_deinit();
}
