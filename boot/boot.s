
;一些关于GRUB的宏定义

MBOOT_HEADER_MAGIC 	equ 	0x1BADB002 	
MBOOT_PAGE_ALIGN 	equ 	1 << 0    	
MBOOT_MEM_INFO 		equ 	1 << 1
MBOOT_HEADER_FLAGS 	equ 	MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM 		equ 	- (MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)



[BITS 32]
section .text

dd MBOOT_HEADER_MAGIC 	
dd MBOOT_HEADER_FLAGS   
dd MBOOT_CHECKSUM


[GLOBAL start]			;入口地址
[EXTERN kern_entry]

start:
	cli  			
	mov esp, STACK_TOP 
	mov ebp, 0 
	and esp, 0FFFFFFF0H	
	call kern_entry
	
stop:
	hlt 			
	jmp stop 


section .bss 			 
stack:
	resb 32768 	 	

STACK_TOP equ $-stack-1 	 
