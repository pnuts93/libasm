section .text
    global ft_strlen

ft_strlen:
    ; Arguments:
    ; rdi - pointer to the null-terminated string

    push rbp          ; save the base pointer
    mov rbp, rsp      ; set up the stack frame

    xor rax, rax      ; zero out the length counter
    mov rcx, -1       ; set up the loop counter

.loop:
    inc rcx           ; increment the loop counter
    cmp byte [rdi+rcx], 0 ; check for null terminator
    jne .loop         ; repeat until null terminator is found

    mov rax, rcx      ; set the length counter to the loop counter

    mov rsp, rbp      ; restore the stack pointer
    pop rbp           ; restore the base pointer
    ret               ; return the length in rax
