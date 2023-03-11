section .text
    global ft_strcmp

ft_strcmp:
    ; Arguments:
    ; rdi - pointer to the first string
    ; rsi - pointer to the second string

    push rbp          ; save the base pointer
    mov rbp, rsp      ; set up the stack frame
    xor rcx, rcx      ; zero out counter
    xor rax, rax      ; zero out register for s1
    xor rbx, rbx      ; zero out register for s2

.loop:
    mov al, byte [rdi + rcx] ; load a byte from the first string
    mov bl, byte [rsi + rcx] ; load a byte from the second string
    cmp al, bl        ; compare the bytes
    jne .done         ; jump to the exit code if they are different
    inc rcx           ; increment counter
    cmp al, 0         ; check for null terminator
    jne .loop         ; repeat until null terminator is found

.done:
    cmp al, bl        ; compare the bytes
    je .equal         ; if equal
    jg .greater       ; if the byte in s1 is greater than the one in s2
    jl .lower         ; if the byte in s1 is lower than the one in s2

.equal:
    mov rax, 0        ; set return value to 0
    jmp .end          ; finish

.greater:
    mov rax, 1        ; set return value to 1
    jmp .end          ; finish

.lower:
    mov rax, -1       ; set return value to -1
    jmp .end          ; finish

.end:
    mov rsp, rbp      ; restore the stack pointer
    pop rbp           ; restore the base pointer
    ret               ; return the result in al
