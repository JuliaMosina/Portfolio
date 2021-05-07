				global _ft_strlen		; size_t strlen(const char *s);
				section .text

_ft_strlen:
				xor		rax, rax
.loop:
				cmp		byte[rdi + rax], 0;
				je 		.exit
				inc 	rax
				jmp 	.loop
.exit:
				ret
