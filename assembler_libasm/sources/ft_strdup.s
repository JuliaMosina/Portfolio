				global _ft_strdup		; char *strdup(const char *s1);
				extern ___error
				extern _malloc
				extern _ft_strlen
				extern _ft_strcpy
				section .text

_ft_strdup:
				xor		rax, rax
				push	rdi
				call	_ft_strlen
				mov		rdi, rax
				inc 	rdi
				call	_malloc
				jc		.error
				pop		rsi
				mov		rdi, rax
				call	_ft_strcpy
				jmp		.exit
.error:
				push	rax
				call	___error
				pop		rdx
				mov		[rax], rdx
				mov		rax, 0
				jmp		.exit
.exit:
				ret
