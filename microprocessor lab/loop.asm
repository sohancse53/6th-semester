.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
 
    mov bl,49
  
    
    LOOP:
    mov ah,2
    mov dl,bl
    int 21h
    
     mov ah,2
  mov dl,10
  int 21h   ;newline
  mov dl,13
  int 21h
  
  
  
    inc bl
    cmp bl,57
    jle LOOP
 
   
     
     EXIT:
     
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN