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
	ADD R7,R0,#16
	ADD R6,R1,#16
	LDR R8,=ARR
	ADDS R8,#16
	MOV R2,#4
	MOV R5,#0
	MOV R9,#0;
loop	LDR R3,[R0]
		LDR R4,[R1]
		ADDS R3,R9
		ADDS R3,R4
		ADC R9,#0
		STR R3,[R8]
		SUBS R8,#4
		SUBS R1,#4
		SUBS R0,#4
		SUBS R2,#1
		BNE loop

STOP
	B STOP
VAL1 DCD 1,2,3,4
VAL2 DCD 1,2,3,4
	AREA mydata, DATA, READWRITE
ARR DCD 1 ;DST location in data memory
	END