section .text
    global ft_strcpy

ft_strcpy:
    ; Arguments:
    ; rdi - pointer to the destination string
    ; rsi - pointer to the source string

    cmp rsi, 0
    je null_return

    push rbp          ; save the base pointer
    mov rbp, rsp      ; set up the stack frame
    xor rcx, rcx      ; zero-out the counter

.loop:
    mov al, byte [rsi + rcx] ; load a byte from the source string
    mov byte [rdi + rcx], al ; store the byte in the destination string
    inc rcx           ; increment the source pointer
    cmp al, 0         ; check for null terminator
    jne .loop         ; repeat until null terminator is found

    mov rsp, rbp      ; restore the stack pointer
    pop rbp           ; restore the base pointer
    mov rax, rdi      ; set the return value
    ret               ; return the destination string pointer

null_return:
    mov rax, 0        ; set return value to 0
    ret               ; return