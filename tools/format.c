#include "format.h"
#include "debug.h"

void print_ch_format(char ch, int num){
	
	int i = 0;
	for(i = 0; i < num; i++)
		printk("%c", ch);
	printk("\n");
	
}
