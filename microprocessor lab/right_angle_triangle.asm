.model small
.stack 100h
.data
VAR DB ?
.code
MAIN PROC  
  MOV AH, 1
  INT 21H
  SUB AL, 48
  MOV VAR, AL
  
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
    
  MOV CX,0
  MOV CL, VAR
  MOV BL, 1
  
  TOP:
  MOV CX,BX
  
  LEVEL1:
  CMP BL,VAR
  JG EXIT
  
  MOV AH, 2
  MOV DL, '*'
  INT 21H
  
  LOOP LEVEL1
  
  INC BL
  
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  
  LOOP TOP
  
  
 
 
 
 
 EXIT:
 
 
 
 MOV AH, 4CH
 INT 21H
 MAIN ENDP

END MAIN




