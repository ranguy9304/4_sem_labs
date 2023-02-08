	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=ARR
	
	MOV R2,#0
	MOV R3,#10
loop 	LDR R4,[R0]
		ADDS R2,R4
		ADDS R0,#4
		SUBS R3,#1
		BNE loop
	LDR R1,=RESULT
	STR R2,[R1]
	
STOP
	B STOP
ARR DCD 1,2,3,4,5,6,7,8,9,10
	AREA data,DATA,READWRITE
RESULT DCD 0
	END