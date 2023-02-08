	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=VAL1
	LDR R1,=VAL2
	LDR R2,[R0]
	LDR R3,[R1]
	LDR R4,=ARR
	SUBS R5,R2,R3
	STR R5,[R4]
	
	

STOP
	B STOP
VAL1 DCD 10
VAL2 DCD 12
	AREA mydata, DATA, READWRITE
ARR DCD 1 ;DST location in data memory
	END