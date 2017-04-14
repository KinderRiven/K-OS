#include "debug.h"
#include "types.h"
#include "gdt.h"
#include "console.h"

extern gdt_entry_t gdt_entries[GDT_LENGTH];
extern gdt_ptr_t gdt_ptr;

//extern uint32_t stack;

uint32_t g_debug3 = 3; 

void kernel_print_debug()
{
	printk("g_debug3 val = %d, address = 0x%x\n", g_debug3, &g_debug3);	
}

void stack_print_debug()
{
	//printk("stack address is 0x%x\n", &stack);
}

void gdt_print_debug()
{
	printk("gdt address is 0x%x\n", gdt_entries);	
	printk("gdt_ptr address is 0x%x, 0x%x\n", gdt_ptr.base, gdt_ptr.limit);
}
