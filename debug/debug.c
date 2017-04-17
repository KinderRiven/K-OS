#include "debug.h"
#include "types.h"
#include "gdt.h"
#include "console.h"
#include "format.h"
#include "idt.h"
#include "pmm.h"

extern gdt_entry_t gdt_entries[GDT_LENGTH];
extern gdt_ptr_t gdt_ptr;

extern uint32_t stack;
extern uint32_t s_top;

uint32_t g_debug3 = 3; 

void kernel_print_debug()
{
	printk("g_debug3 val = %d, address = 0x%x\n", g_debug3, &g_debug3);	
}

void stack_print_debug()
{
	printk("stack start address 0x%x, max_size is 0x%x(%d)B \n", &stack, &s_top - &stack, &s_top - &stack);
}

void gdt_print_debug()
{
	printk("GDT address is 0x%x\n", gdt_entries);	
	printk("GDT's value is 0x%x(GDT's size 0x%x)\n", gdt_ptr.base, gdt_ptr.limit);

}

void interrupt_run_debug()
{
	asm volatile("int $0x3");
	asm volatile("int $0x4");
}

void memory_alloc_debug()
{
	uint32_t alloc_addr = NULL;	
	uint8_t i;
	
	for(i = 0; i < 3; i++){
		alloc_addr = pmm_alloc_page();
		printk("Test Physical Memory: 0x%08X\n", alloc_addr);
	}
}	
