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
	ADD R0,#12
	ADD R1,#12
	LDR R2,=ARR
	ADDS R2,#12
	MOV R7,#4
	MOV R6,#0
loop	LDR R3,[R0]
		LDR R4,[R1]
		ADDS R3,R6
		ADDS R3,R4
		ADC R6,#0
		STR R3,[R2]
		SUBS R2,#4
		SUBS R1,#4
		SUBS R0,#4
		SUBS R7,#1
		BNE loop

STOP
	B STOP
VAL1 DCD 1,2,3,1000
VAL2 DCD 1,2,3,2000
	AREA mydata, DATA, READWRITE
ARR DCD 1 ;DST location in data memory
	END