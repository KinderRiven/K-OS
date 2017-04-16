#include "stack.h"
#include "debug.h"

void stack_add(uint32_t a, uint32_t b)
{
	printk("%d + %d = %d\n", a, b, a + b);
}
