GLOBAL INx
GLOBAL OUTx
GLOBAL getSeconds
GLOBAL getMinutes
GLOBAL getHours
GLOBAL cuatro
;	INx(port)
INx:
	push ebp
	mov ebp, esp
	push edx
	mov dx, [ebp+8]
	in al, dx
	pop edx
	pop ebp 
	ret
;	OUTx(PORT, VAL)
OUTx:
	push ebp
	mov ebp, esp
	push edx
	mov al, [ebp+12]
	mov dx, [ebp+8]
	out dx, al
	pop edx
	pop ebp
	ret
getSeconds:
	push ebp
	mov ebp,esp
	mov al, 0
	out 70h, al
	in al, 71h
	pop ebp
	ret
getMinutes:
	push ebp
	mov ebp,esp
	mov al, 2
	out 70h, al
	in al, 71h
	pop ebp
	ret
getHours:
	push ebp
	mov ebp,esp
	mov al, 4
	out 70h, al
	in al, 71h
	pop ebp
	ret	
cuatro:
	push ebp
	mov ebp, esp
	mov eax, 4
	pop ebp
	ret