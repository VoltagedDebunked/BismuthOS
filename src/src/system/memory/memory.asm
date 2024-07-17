section .text
    global init_memory

init_memory:
    mov eax, 0x2000000000
    mov ebx, 0x1000000000

    mov eax, 4
    mov ebx, 1
    mov ecx, memory_msg
    mov edx, memory_msg_len
    int 0x80

    ret

section .data
    memory_msg db "Memory initialized.", 0x0A, 0
    memory_msg_len equ $ - memory_msg
