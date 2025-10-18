.model small
.stack 100h
.data
VAR DB ?
.code
MAIN PROC
    mov ax,@data
    mov ds,ax

    mov ah,1
    int 21h
    sub al,48
    mov var,al

    mov ah,2
    mov dl,0Dh
    int 21h
    mov dl,0Ah
    int 21h

    mov cl,var
    mov ch,0
    mov bl,1

outer_loop:
    mov al,var
    sub al,bl
    mov bh,al

print_space:
    cmp bh,0
    je print_star
    mov ah,2
    mov dl,' '
    int 21h
    dec bh
    jmp print_space

print_star:
    mov al,bl
    shl al,1
    dec al
    mov bh,al

star_loop:
    cmp bh,0
    je row_done
    mov ah,2
    mov dl,'*'
    int 21h
    dec bh
    jmp star_loop

row_done:
    mov ah,2
    mov dl,0Dh
    int 21h
    mov dl,0Ah
    int 21h

    inc bl
    loop outer_loop

    mov ah,4Ch
    int 21h
MAIN ENDP
end MAIN
