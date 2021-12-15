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
	L1 SDWORD 0

.data
	buffer BYTE 256 dup(0)
	ka SDWORD 0
	EKLERz SDWORD 0
	la SDWORD 0

.code

i PROC 
	push 0
	jmp local0
local0:
	pop eax
	ret
i ENDP

k PROC 
	ret
k ENDP

main PROC
	call ExitProcess
main ENDP
end maing PROC 
	push 0
	jmp local1
		jmp theend
local1:
	pop eax
	ret
g ENDP

l PROC 
	ret
l ENDP

