mov ax, 0A000h ; The offset to video memory
mov es, ax ; We load it to ES through AX, becouse immediate operation is not allowed on ES
mov ax, 0 ; 0 will put it in top left corner. To put it in top right corner load with 320, in the middle of the screen 32010.
mov di, ax ; load Destination Index register with ax value (the coords to put the pixel)
mov dl, 7 ; Grey color.
mov [es:di], dl ; And we put the pixel
