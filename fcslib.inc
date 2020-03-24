; Structure used by file I/O functions

FC.FDB	equ	0		; FDB address (2 bytes)
FC.MODE	equ	FC.FDB + 2	; access mode and status bits (1 byte)
FC.LUN	equ	FC.MODE + 1	; LUN (1 byte)
FC.EFN	equ	FC.LUN + 1	; event flag number (1 byte)
FC.BUF	equ	FC.EFN + 1	; I/O buffer address (2 bytes)
FC.CNT	equ	FC.BUF + 2	; chars in buffer (2 bytes)
FC.CUR	equ	FC.CNT + 2	; index of current char in buffer (2 bytes)
FC.BLK	equ	FC.CUR + 2	; current block number in buffer (4 bytes)

FCSIZ	equ	FC.BLK + 4	; size of the above structure

; Mode bits

FM.RD	equ	0		; open for read
FM.WR	equ	1		; open for write
FM.WA	equ	2		; open for append
FM.DV	equ	3		; device mode (not a file)
FM.TT	equ	4		; device is a terminal

; Status bits

FS.BV	equ	5		; buffer contains valid data
FS.BM	equ	6		; buffer modified (write pending)

; Macro to generate a storage region for file I/O

FSR$	MACRO	fdb,mode,lun,efn,buf
	local	lfdb,lbuf
	ifnb	<fdb>
	dw	fdb
	else
	dw	lfdb
	endif
	db	mode,lun,efn
	ifnb	<buf>
	dw	buf
	else
	dw	lbuf
	endif
	dw	0,0,0,0
	ifb	<fdb>
lfdb:	ds	FINFSZ
	endif
	ifb	<buf>
lbuf:	ds	512
	endif
	ENDM

