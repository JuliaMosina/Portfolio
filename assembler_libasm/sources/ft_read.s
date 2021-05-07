			global _ft_read			; ssize_t read(int fildes, void *buf, size_t nbyte);
			extern ___error
			section .text

_ft_read:
			mov		rax, 0x02000003
			syscall
			jc 		.error
			jmp		.exit
.error:
			mov		r8, rax
			call 	___error
			mov		[rax], r8
			mov		rax, -1
			jmp		.exit
.exit:
			ret
