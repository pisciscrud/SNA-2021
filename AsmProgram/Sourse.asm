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
	L1 BYTE "asda", 0
	L2 BYTE "message", 0

.data
	buffer BYTE 256 dup(0)

.code

fun2 PROC 
	push offset L1
	call OutputStrLn
	ret
fun2 ENDP

main PROC
	call fun2
	push offset L2
	call OutputStrLn
	call ExitProcess
main ENDP
end main