; 将数据翻转
assume cs:code
code segment
        dw 0123h, 0456h, 0789h, 0abch
        dw 0, 0, 0, 0
 start: mov ax, cs
        mov ss, ax ; 配置堆内存地址
        mov sp, 0fh; 配置堆顶地址
        
        mov bx, 0
        mov cx, 4
        
     s: push cs:[bx]
        add bx, 2
        loop s
        
        mov bx, 0
        mov cx, 4
        
    s0: pop cs:[bx]
        add bx, 2
        loop s0
        
        mov ax, 4c00h
        int 21h
        
code ends
end start