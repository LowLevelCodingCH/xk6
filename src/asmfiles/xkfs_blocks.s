user_amount:
	db 2
users: ; Users are stored in this file block
	db "LLCCH", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ; Size for username (16)
	db "Passcode", 0, 0, 0, 0, 0, 0, 0, 0 ; Passcode (16)
	db "Root", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ; Size for username (16)
	db "Rootuser", 0, 0, 0, 0, 0, 0, 0, 0 ; Passcode (16)




times 512 - ($-$$) db 0
times (512*255) db 0 ; Make all blocks 0x00 except 1st; 256 blocks total
