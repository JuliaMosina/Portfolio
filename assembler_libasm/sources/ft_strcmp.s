				global _ft_strcmp		; int strcmp(const char *s1, const char *s2);
				section .text

_ft_strcmp:
				xor		rax, rax
				cmp		byte[rdi + rax], 0
				je		.end_of_str1
				cmp     byte[rsi + rax], 0
				je		.end_of_str2
				jmp		.compare
.end_of_str1:
				cmp     byte[rsi + rax], 0
				jne		.compare
				xor     rax, rax
				jmp		.exit
.end_of_str2:
				cmp		byte[rdi + rax], 0
				jne     .compare
				xor     rax, rax
				jmp		.exit
.loop:
				inc		rax
				cmp		byte[rdi + rax], 0
				je		.end_of_str1
				cmp     byte[rsi + rax], 0
				je		.end_of_str2
				jmp 	.compare
.compare:
				xor		r8, r8
				xor     r9, r9
				mov		r8b, byte[rdi + rax]
				mov		r9b, byte[rsi + rax]
				cmp		r8b, r9b
				je		.loop
				jmp		.difference
.difference:
				sub		r8, r9
				mov		rax, r8
				jmp		.exit
.exit:
				ret
