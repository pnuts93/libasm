section .text
global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:
    ; Arguments:
    ; rdi - pointer to string to duplicate

    cmp rdi, 0              ; verify validity of pointer
    je null_return          ; conditional jump to null_return
    push rbp                ; Save caller's frame pointer
    mov rbp, rsp            ; Set up our own frame pointer

    push rdi                ; save pointer to source in stack
    call ft_strlen          ; Call strlen to get length of string

    add rax, 1              ; Add 1 to length for null terminator
    mov rdi, rax            ; First argument to malloc
    call malloc WRT ..plt   ; Call malloc
    
    pop rsi                 ; Retrieve from stack the source pointer for strcpy
    mov rdi, rax            ; Destination for strcpy
    call ft_strcpy          ; Call strcpy to copy input string

    pop rbp                 ; Restore caller's frame pointer
    ret                     ; Return pointer to duplicated string

null_return:
    mov rax, 0              ; Set return value to 0
    ret                     ; Return