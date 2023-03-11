section .text
    global ft_write
    extern __errno_location

ft_write:
    ; Arguments:
    ; rdi - file descriptor
    ; rsi - buffer address
    ; rdx - buffer length

    push rbp          ; save the base pointer
    mov rbp, rsp      ; set up the stack frame

    mov rax, 1        ; write system call number
    syscall           ; perform the system call
    cmp rax, 0        ; evaluates if rax is negative
    jl .end_err       ; if yes the syscall issued an error
    jge .end          ; if not the syscall was successful

.end_err:
    mov rcx, -1       ; store -1 in rcx for following multiplication
    mul rcx           ; error code must be positive
    mov rdx, rax      ; save the return value of the syscall
    call __errno_location WRT ..plt ; call function to get a pointer to errno
    mov [rax], rdx    ; copy syscall return value in errno
    mov rax, -1       ; set return value of ft_write to -1
    jmp .end          ; jump to end

.end:
    mov rsp, rbp      ; restore the stack pointer
    pop rbp           ; restore the base pointer
    ret               ; return the number of bytes read in rax
