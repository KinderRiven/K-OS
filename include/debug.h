#ifndef INCLUDE_DEBUG_H_
#define INCLUDE_DEBUG_H_

#include "console.h"
#include "vargs.h"

#define assert(x, info)                                       	\
	do {                                                	\
		if (!(x)) {                                     \
			panic(info); 		     		\
		}                                               \
	} while (0)

// 编译期间静态检测
#define static_assert(x)                                	\
	switch (x) { case 0: case (x): ; }

// 初始化 Debug 信息
void init_debug();

// 内核的打印函数
void printk(const char *format, ...);

// 内核的打印函数 带颜色
void printk_color(console_color back, console_color fore, const char *format, ...);

// debug函数集
void kernel_print_debug();

void gdt_print_debug();

void stack_print_debug();

void debug_s_1();

void interrupt_debug();
#endif 	// INCLUDE_DEBUG_H_
