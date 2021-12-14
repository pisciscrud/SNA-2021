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
	L1 SDWORD 72
	L2 SDWORD -16
	L3 SDWORD 605
	L4 SDWORD -3
	L5 SDWORD 2

.data
	buffer BYTE 256 dup(0)
	EKLERoctd SDWORD 0
	EKLERocts SDWORD 0
	EKLERdec SDWORD 0
	EKLERbinf SDWORD 0
	EKLERbins SDWORD 0
	EKLERdec SDWORD 0

.code

main PROC
	push L1
	pop EKLERoctd
	push L2
	pop EKLERocts
	push L3
	pop EKLERdec
	push L4
	pop EKLERbinf
	push L5
	pop EKLERbins
	push EKLERocts
	call OutputIntLn
	push EKLERbinf
	call OutputIntLn
	push EKLERbins
	call OutputIntLn
	call ExitProcess
main ENDP
end main