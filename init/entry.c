#include "types.h"
#include "console.h"
#include "debug.h"
#include "gdt.h"
#include "stack.h"
#include "format.h"

uint32_t g_debug0 = 0;
uint32_t g_debug1 = 1;
uint32_t g_debug2 = 2;

uint32_t *a_debug0 = (uint32_t *)0x10a000;
//x010a004 is g_debug0
uint32_t *a_debug1 = (uint32_t *)0x10a008;

static void debug(){

	uint32_t l_debug0 = 0;
	uint32_t l_debug1 = 1;

	//debug	
	print_ch_format('=', 40);

	printk("a_debug0 val = %x, address = 0x%x\n", *a_debug0, a_debug0); 	
	printk("a_debug1 val = %x, address = 0x%x\n", *a_debug1, a_debug1); 	
	
	printk("g_debug0 val = %d, address = 0x%x\n", g_debug0, &g_debug0);	
	printk("g_debug1 val = %d, address = 0x%x\n", g_debug1, &g_debug1);	
	printk("g_debug2 val = %d, address = 0x%x\n", g_debug2, &g_debug2);	
	
	printk("l_debug0 val = %d, address = 0x%x\n", l_debug0, &l_debug0);
	printk("l_debug1 val = %d, address = 0x%x\n", l_debug1, &l_debug1);

	print_ch_format('=', 40);
	
}

static void stack_debug()
{
	stack_add_s();
}

int kern_entry()
{
	//debug_s_1();
	
	init_gdt();
	init_idt();

	console_clear();

	//debug	
	//stack_debug();
	//debug();
	//stack_print_debug();	
	//gdt_print_debug();
	interrupt_debug();
	
	//main run
	printk("Welcome to K'OS! ^_^ \n");
	return 0;
}

