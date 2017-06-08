// 2017 Thomas Hunsaker @thunsaker

#include <pebble.h>
#include "src/c/libs/pebble-assist.h"
#include "src/c/splash.h"

static Window *s_window;
TextLayer *text_layer_title;
BitmapLayer *bitmap_layer_droplet;
static GBitmap *bitmap_droplet;

static int SCREEN_HEIGHT;
static int SCREEN_WIDTH;

static void window_load(Window *window) {
   Layer *window_layer = window_get_root_layer(s_window);
   GRect bounds = layer_get_frame(window_layer);

   window_set_background_color(s_window, PBL_IF_COLOR_ELSE(GColorWhite, GColorBlack));

   SCREEN_HEIGHT = bounds.size.h;
   SCREEN_WIDTH = bounds.size.w;

   text_layer_title = text_layer_create(GRect(0,SCREEN_HEIGHT-PBL_IF_ROUND_ELSE(70,60), SCREEN_WIDTH,40));
   text_layer_set_text_alignment(text_layer_title, GTextAlignmentCenter);
   text_layer_set_text_color(text_layer_title, PBL_IF_COLOR_ELSE(GColorOxfordBlue, GColorWhite));
   text_layer_set_background_color(text_layer_title, PBL_IF_COLOR_ELSE(GColorWhite, GColorBlack));

   text_layer_set_font(text_layer_title, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));

   // TODO: Add message here.
   text_layer_set_text(text_layer_title, "Droplet");
   layer_add_child(window_layer,text_layer_get_layer(text_layer_title));

   bitmap_layer_droplet = bitmap_layer_create(GRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT-40));
	bitmap_layer_set_alignment(bitmap_layer_droplet, GAlignCenter);
	bitmap_layer_set_compositing_mode(bitmap_layer_droplet, GCompOpSet);
	bitmap_layer_set_bitmap(bitmap_layer_droplet, bitmap_droplet);
	layer_add_child(window_layer,bitmap_layer_get_layer(bitmap_layer_droplet));
}

static void window_unload(Window *window) {
	// menu_layer_destroy_safe(s_menu_layer);

	gbitmap_destroy(bitmap_droplet);
}

void splash_deinit(void) {
   // destroy all the things!
   window_destroy_safe(s_window);
}

void splash_hide(void) {
   splash_deinit();
}

void init(void) {
   s_window = window_create();
   window_set_window_handlers(s_window, (WindowHandlers) {
      .load = window_load,
      .unload = window_unload,
   });
   window_stack_push(s_window, true);
}

void splash_show(bool icon, char message[128]) {
   if(icon == true) {
         bitmap_droplet = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DROP_LARGE);
   } else {
         bitmap_droplet = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DROP_OFF_SMALL);
   }
   init();
}
