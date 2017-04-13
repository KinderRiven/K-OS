#ifndef INCLUDE_GDT_H_
#define INCLUDE_GDT_H_

#include "types.h"

#ifndef GDT_LENGTH
	#define GDT_LENGTH 5
#endif

typedef struct gdt_entry_t
{
	uint16_t limit_low;		//00 - 15
	uint16_t base_low; 		//00 - 15;
	uint8_t	 base_middle;	//16 - 23;
	uint8_t  access;		//
	uint8_t  granularity;	//
	uint8_t  base_high;		//24 - 31;

} __attribute__((packed)) gdt_entry_t;



typedef struct gdt_ptr_t
{

	uint32_t base;		//表的线性地址
	uint16_t limit;		//表的长度

} __attribute__((packed)) gdt_ptr_t;


void init_gdt();

void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

extern void gdt_flush(uint32_t);

#endif
