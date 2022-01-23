;将内存ffff:0 - ffff:b copy-> 0:200 - 0:20b 
assume cs:code
code segment
    mov ax, 0ffffh
    mov ds, ax
    mov ax, 0020h ;因bx偏移地址是0开始，得0*16 + 20段地址
    mov es, ax ; es 附加段地址
    
    mov bx, 0
    mov cx, 12
    
    s: mov dl, ds:[bx]
    mov es:[bx], dl
    
    inc bx ; inc ++
    loop s

    mov ax, 4c00h
    int 21h
    
code ends
end