#ifndef INCLUDE_PMM_H_
#define INCLUDE_PMM_H_

#include "multiboot.h"

#define STACK_SIZE 		8192

//最大物理内存
#define PMM_MAX_SIZE 	0x20000000

//物理内存页框大小
#define PMM_PAGE_SIZE 	0x1000

//页面个数
#define PAGE_MAX_SIZE	(PMM_MAX_SIZE / PMM_MAX_SIZE)

//对齐
#define PHY_PAGE_MASK	0xFFFFF000

extern uint32_t kern_start[];

extern uint32_t kern_end[];

void show_memory_map();

void show_memory_all();

void init_pmm();

uint32_t pmm_alloc_page();

void pmm_free_page(uint32_t p);
#endif
