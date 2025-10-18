
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

; add your code here
  mov ah,1
  int 21h
  
  mov bl,al
  int 21h
  
  mov bh,al
  int 21h
  
  mov cl,al
  int 21h
  
  mov ch,al
  
  
  
  mov ah,2
  
  mov dl,bl
  int 21
  
   mov dl,bh
  int 21
  
   mov dl,cl
  int 21
  
   mov dl,ch
  int 21

ret




