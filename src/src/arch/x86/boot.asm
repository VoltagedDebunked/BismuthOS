[BITS 16]
[ORG 0x7C00]

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:init_pm

[BITS 32]
init_pm:
    mov eax, DATA_SEG
    mov ds, eax
    mov es, eax
    mov fs, eax
    mov gs, eax
    mov ss, eax
    mov esp, 0x90000

    call kernel_entry

    hlt

restart:
    mov al, 0xFE
    out 0x64, al
    hlt

shutdown:
    mov ax, 0x1004
    mov dx, 0xB004
    out dx, ax
    hlt

gdt_start:
    dd 0x0000FFFF, 0x00000000
    dd 0x00CF9A00, 0x0000FFFF
    dd 0x00CF9200, 0x0000FFFF
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

CODE_SEG equ 0x08
DATA_SEG equ 0x10

times 510-($-$$) db 0
dw 0xAA55
