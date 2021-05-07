				global _ft_strcpy		; char *strcpy(char *dst, const char *src);
				section .text

_ft_strcpy:
				xor		rax, rax
.loop:
				cmp		byte[rsi + rax], 0;
				je 		.exit
				mov		dl, byte[rsi + rax]
				mov		byte[rdi + rax], dl
				inc 	rax
				jmp 	.loop
.exit:
				mov		byte[rdi + rax], 0
				mov		rax, rdi
				ret
