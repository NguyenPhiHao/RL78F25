;/**********************************************************************************************************************
; * Copyright   :
; * System Name : QINeS-Lite MCAL
; * File Name   : optionbyte.asm
; * Version     : v1.00.00
; * Contents    : Sample option byte file.
; *********************************************************************************************************************/
__WDG_SAMPLE_ENABLE__   .EQU    0   ;
 
.CSEG	OPT_BYTE
$IF (__WDG_SAMPLE_ENABLE__ == 1)
    .DB 0xB7	; Option Byte 0 for WDG Sample App
    .DB 0xF3	; Option Byte 1
    .DB 0xF8	; Option Byte 2
    .DB 0x87	; Option Byte 3
    .DB 0xFF	; Security Option Byte
$ELSE
    .DB 0x6E	; Option Byte 0
    .DB 0xF3	; Option Byte 1
    .DB 0xF8	; Option Byte 2
    .DB 0x87	; Option Byte 3
    .DB 0xFF	; Security Option Byte
$ENDIF