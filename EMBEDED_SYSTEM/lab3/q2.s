	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000 
	DCD Reset_Handler 
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC
	LDR R1, =DST
	MOV R2, #0 
	LDR R3, [R0]
	MLA R2, R3, R3, R3
	LSR R2, #1
	STR R2, [R1]
STOP
	B STOP;
SRC DCD 5
	AREA mydata, DATA, READWRITE
DST DCD 0   
	END