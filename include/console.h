#ifndef INCLUDE_CONSOLE_H_
#define INCLUDE_CONSOLE_H_

#include "types.h"

typedef enum{

	c_black = 0,
	c_blue = 1,
	c_green = 2,
	c_cyan = 3,
	c_red = 4,
	c_magenta = 5,
	c_brown = 6,
	c_light_grey = 7,
	c_dark_grey = 8,
	c_light_blue = 9,
	c_light_green = 10,
	c_light_cyan = 11,
	c_light_red = 12,
	c_light_magenta = 13,
	c_light_brown  = 14, 	// yellow
	c_white = 15

} console_color;


void console_clear();

void console_clear_color(console_color bg_color, console_color tx_color);

void console_printc(char ch);

void console_printc_color(char ch, console_color bg_color, console_color tx_color);

void console_prints(const char *buffer);

void console_prints_color(const char *buffer, console_color bg_color, console_color tx_color);

void console_move_cursor(uint8_t cursor_x, uint8_t cursor_y);


#endif
