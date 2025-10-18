
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

 mov ah,1
 int 21h
 mov bl,al
 
 mov ah,2
 mov dl,010
 int 21h     ;new line
 mov dl,013
 int 21h
 
 mov ah,1
 int 21h
 mov bh,al
 
 
 sub bl,bh
 add bl,48

 mov ah,2
 mov dl,010
 int 21h    ;new line
 mov dl,013
 int 21h
 
 mov ah,2
 mov dl,bl
 int 21h
 
 

ret




