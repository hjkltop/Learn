assume cs:test
test segment
	mov ax, 0122H
	mov bx, 0322h
	sub ax, bx
	
	mov ax, 4c00h
	int 21h
	
test ends
end