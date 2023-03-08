section .text
    global ft_strcmp

ft_strcmp:
    ; Arguments:
    ; rdi - pointer to the first string
    ; rsi - pointer to the second string

    push rbp          ; save the base pointer
    mov rbp, rsp      ; set up the stack frame

.loop:
    mov al, byte [rdi] ; load a byte from the first string
    mov bl, byte [rsi] ; load a byte from the second string
    cmp al, bl        ; compare the bytes
    jne .done         ; jump to the exit code if they are different
    inc rdi           ; increment the first string pointer
    inc rsi           ; increment the second string pointer
    cmp al, 0         ; check for null terminator
    jne .loop         ; repeat until null terminator is found

.done:
    sub al, bl        ; subtract the last compared bytes to get the result
    mov rsp, rbp      ; restore the stack pointer
    pop rbp           ; restore the base pointer
    ret               ; return the result in al
