section .text
    global ft_read

ft_read:
    ; Arguments:
    ; rdi - file descriptor
    ; rsi - buffer address
    ; rdx - buffer length

    push rbp          ; save the base pointer
    mov rbp, rsp      ; set up the stack frame

    mov rax, 0        ; read system call number
    syscall           ; perform the system call

    mov rsp, rbp      ; restore the stack pointer
    pop rbp           ; restore the base pointer
    ret               ; return the number of bytes read in rax
