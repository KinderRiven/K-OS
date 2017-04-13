#include "types.h"
#include "console.h"
#include "debug.h"
#include "gdt.h"

uint32_t g_debug0 = 0;
uint32_t g_debug1 = 1;
uint32_t g_debug2 = 2;

extern uint32_t glb_mboot_ptr;
uint32_t *a_debug0 = (uint32_t *)0x10a000;
//x010a004 is g_debug0
uint32_t *a_debug1 = (uint32_t *)0x10a008;

int kern_entry()
{

	console_clear();
	
	uint32_t l_debug0 = 0;
	uint32_t l_debug1 = 1;
	//debug
	
	printk("=========================================================\n");

	printk("m_boot_ptr val = %x, address = 0x%x\n", glb_mboot_ptr, &glb_mboot_ptr);
	printk("a_debug0 val = %x, address = 0x%x\n", *a_debug0, a_debug0); 	
	printk("a_debug1 val = %x, address = 0x%x\n", *a_debug1, a_debug1); 	
	
	printk("g_debug0 val = %d, address = 0x%x\n", g_debug0, &g_debug0);	
	printk("g_debug1 val = %d, address = 0x%x\n", g_debug1, &g_debug1);	
	printk("g_debug2 val = %d, address = 0x%x\n", g_debug2, &g_debug2);	
	
	kernel_print_debug();
	
	printk("l_debug0 val = %d, address = 0x%x\n", l_debug0, &l_debug0);
	printk("l_debug1 val = %d, address = 0x%x\n", l_debug1, &l_debug1);

	stack_print_debug();	
	gdt_print_debug();
	
	printk("=========================================================\n");

	//main run
	printk("Welcome to K'OS! ^_^ \n");
	init_gdt();
	
	return 0;
}

