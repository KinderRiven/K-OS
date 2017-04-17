#include "types.h"
#include "console.h"
#include "debug.h"
#include "gdt.h"
#include "stack.h"
#include "format.h"
#include "timer.h"
#include "idt.h"
#include "pmm.h"

int kern_entry()
{
	
	init_gdt();
	init_idt();

	init_pmm();
	console_clear();

	show_memory_all();
	show_memory_map();

	memory_alloc_debug();	
	printk("Welcome to K'OS! ^_^ \n");
	return 0;
}

