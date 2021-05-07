			global _ft_write			; ssize_t write(int fildes, const void *buf, size_t nbyte);
			extern ___error
			section .text

_ft_write:
			mov		rax, 0x02000004
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
