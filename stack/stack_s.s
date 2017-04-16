
[GLOBAL stack_push_b]
[GLOBAL stack_add_s]
[EXTERN stack_add]

stack_push_b:
	
	ret

stack_add_s:	

	push 1
	push 2
	call stack_add
	add esp, 8
	ret
