.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ../Debug/StaticLibrary.lib
ExitProcess PROTO :DWORD

EXTRN BREAKL: proc
EXTRN OutputInt: proc
EXTRN OutputStr: proc
EXTRN OutputIntLn: proc
EXTRN OutputStrLn: proc
EXTRN slen: proc
EXTRN scpy: proc

.stack 4096

.const
	L1 BYTE "sadsa", 0
	L2 SDWORD 0
	L3 SDWORD 1
	L4 SDWORD 10
	L5 SDWORD -10
	L6 SDWORD -12
	L7 SDWORD 6
	L8 SDWORD -1
	L9 SDWORD 12
	L10
	L11 BYTE "Результат=", 0

.data
	buffer BYTE 256 dup(0)
	facsymb DWORD ?
	facfirst SDWORD 0
	facsecond SDWORD 0
	facz SDWORD 0
	facres SDWORD 0
	mainres SDWORD 0
	mainfirst SDWORD 0
	mainsec SDWORD 0
	mainresult SDWORD 0
	mainsymb BYTE ?

.code

fac PROC faci : SDWORD
	push offset L1
	pop facsymb
	mov eax, faci
	cmp eax, L2
	jz m0
	jnz m1
	je m1
m0:
	push 1
	jmp local0
	jmp e0
m1:
	push L4
	pop facfirst
	push L5
	pop facsecond
	push faci
	push facfirst
	push L6
	pop eax
	pop ebx
	mul ebx
	push eax
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop facz
	push faci
	push facz
	pop edx
	push facz
	call fac
	push eax
	pop eax
	pop ebx
	mul ebx
	push eax
	pop facres
	push facres
	jmp local0
e0:
local0:
	pop eax
	ret
fac ENDP

main PROC
	push L7
	pop edx
	push L7
	call fac
	push eax
	pop mainres
	push L4
	pop mainfirst
	push L5
	pop mainsec
	push mainfirst
	push mainsec
	push L8
	pop ebx
	pop eax
	cdq
	idiv ebx
	push eax
	push L9
	pop eax
	pop ebx
	mul ebx
	push eax
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop mainresult
	pop mainsymb
	push offset L11
	call OutputStr
	call ExitProcess
main ENDP
end main