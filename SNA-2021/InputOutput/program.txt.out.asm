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
EXTRN ABS: proc
EXTRN DEG: proc

.stack 4096

.const
	L1 SDWORD 4
	L2 SDWORD 6
	L3 SDWORD 14
	L4 SDWORD 5
	L5 SDWORD 1

.data
	buffer BYTE 256 dup(0)
	EKLERa SDWORD 0
	EKLERb SDWORD 0
	EKLERc SDWORD 0
	EKLERexpr SDWORD 0

.code

main PROC
	push L1
	pop EKLERa
	push L2
	pop EKLERb
	push L3
	pop EKLERc
	push EKLERa
	push EKLERb
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push EKLERc
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push L2
	pop ebx
	pop eax
	cdq
	idiv ebx
	push edx
	push L4
	push EKLERa
	push L5
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop eax
	pop ebx
	mul ebx
	push eax
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop EKLERexpr
	push EKLERexpr
	call OutputIntLn
	call ExitProcess
main ENDP
end main