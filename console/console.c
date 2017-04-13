#include "types.h"
#include "console.h"
#include "common.h"

static uint16_t *video_memory = (uint16_t *)0xB8000;

static uint8_t now_cursor_x = 0;
static uint8_t now_cursor_y = 0;


void console_clear()
{
	console_clear_color(c_black, c_white);			
}


void console_clear_color(console_color bg_color, console_color tx_color)
{	

	uint8_t  blank_color = tx_color | (bg_color << 4);
	uint16_t blank = (' ' | (blank_color << 8));
	int i;

	for(i = 0; i < 80 * 25; i++){
		video_memory[i] = blank;
	}

	console_move_cursor(0, 0);
}

void console_move_cursor(uint8_t cursor_x, uint8_t cursor_y)
{
	uint16_t cursorLocation = cursor_y * 80 + cursor_x;	

	outb(0x3D4, 14);                  	
	outb(0x3D5, cursorLocation >> 8); 	
	outb(0x3D4, 15);                  	
	outb(0x3D5, cursorLocation);     	
	
	now_cursor_x = cursor_x;
	now_cursor_y = cursor_y;
}




void console_printc_color(char ch, console_color bg_color, console_color tx_color)
{

	uint16_t cursorLocation = now_cursor_y * 80 + now_cursor_x;
	uint8_t  color = tx_color | (bg_color << 4);	
	uint16_t text = ch | (color << 8); 

	if(ch == '\n')
	{
		now_cursor_y ++;
		now_cursor_x = 0;
		console_move_cursor(now_cursor_x, now_cursor_y);
	}
	else
	{
		video_memory[cursorLocation] = text;
		cursorLocation ++;		
		console_move_cursor(cursorLocation % 80, cursorLocation / 80);
	}
}

void console_printc(char ch)
{
	console_printc_color(ch, c_black, c_white);
}


void console_prints_color(const char *buffer, console_color bg_color, console_color tx_color)
{

	int pos = 0;
	
	while(buffer[pos] != '\0')
	{
		console_printc_color(buffer[pos], bg_color, tx_color);
		pos++;
	}	

}

void console_prints(const char *buffer)
{
	console_prints_color(buffer, c_black, c_white);
}
