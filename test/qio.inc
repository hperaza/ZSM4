; QDB structure offsets

Q.FUNC	equ	0		; function code (1 byte)
Q.SUBF	equ	Q.FUNC + 1	; subfunction (1 byte)
Q.LUN	equ	Q.SUBF + 1	; logical unit number (1 byte)
Q.EFN	equ	Q.LUN + 1	; event flag number (1 byte)
Q.WAIT	equ	Q.EFN + 1	; wait flag (1 byte)
Q.IOSB	equ	Q.WAIT + 1	; user I/O Status Block address (2 bytes)
Q.P1	equ	Q.IOSB + 2	; function-dependent param 1 (2 bytes)
Q.P2	equ	Q.P1 + 2	; function-dependent param 2 (2 bytes)
Q.P3	equ	Q.P2 + 2	; function-dependent param 3 (2 bytes)
Q.P4	equ	Q.P3 + 2	; function-dependent param 4 (2 bytes)
Q.P5	equ	Q.P4 + 2	; function-dependent param 5 (2 bytes)

QDBSZ	equ	Q.P5 + 2	; QDB size

; Standard parameter mapping

Q.BUF	equ	Q.P1		; buffer address in user space (2 bytes)
Q.LEN	equ	Q.P2		; byte count (2 bytes)
Q.BLK	equ	Q.P3		; block number (4 bytes)
Q.OFS	equ	Q.P5		; offset within block (2 bytes)

; QIO function codes

; Standard functions

IO.KIL	equ	0		; cancel I/O requests
IO.ATT	equ	1		; attach device
IO.DET	equ	2		; detach device
IO.RLB	equ	3		; read logical block
IO.WLB	equ	4		; write logical block
IO.SEC	equ	5		; sense characteristics

; Additional disk driver functions

IO.RPB	equ	6		; read physical block
IO.WPB	equ	7		; write physical block
IO.FMT	equ	8		; format track

; Additional terminal functions

IO.RPR	equ	9		; read with prompt
IO.HNG	equ	10		; hangup remote line
SF.GMC	equ	11		; get multiple characteristics
SF.SMC	equ	12		; set multiple characteristics

; Terminal sub-functions (some can be ORed)

TF.AST	equ	01h		; attach with AST
TF.RNE	equ	01h		; read with no echo
TF.RAL	equ	02h		; read all bits (unfiltered)
TF.WAL	equ	02h		; write all bits
TF.TMO	equ	04h		; read with timeout
TF.WBT	equ	08h		; break-through write
TF.CCO	equ	10h		; cancel ^O
TF.XOF	equ	20h		; send XOFF

; Filesystem requests

IO.CRE	equ	20		; create file
IO.ACC	equ	21		; access (open) file
IO.DEA	equ	22		; deaccess (close) file
IO.RVB	equ	23		; read virtual block
IO.WVB	equ	24		; write virtual block
IO.RAT	equ	25		; read attributes
IO.WAT	equ	26		; write attributes
IO.UNL	equ	27		; unlock file
IO.DEL	equ	28		; delete file
IO.REN	equ	29		; rename file
IO.CLN	equ	30		; cleanup file
IO.MNT	equ	31		; mount device
IO.DSM	equ	32		; dismount device
IO.FFS	equ	33		; flush all disk buffers

; File I/O subfunctions (can be ORed)

SF.ACR	equ	01h		; access (open) for read
SF.ACW	equ	02h		; access (open) for write
SF.SHR	equ	08h		; open in shared mode
SF.TMP	equ	20h		; create temporary file (delete on close)
SF.DIR	equ	40h		; create directory
SF.CTG	equ	80h		; create contiguous file

; RSX-11M style QIO macros

QIO$	macro	func,lun,efn,wait,iosb,args
	dw	func		;; note: 16-bit Q.FUNC + Q.SUBF
	db	lun,efn		;; Q.LUN, Q.EFN
	ifb	<wait>
	db	0		;; Q.WAIT = 0
	else
	db	wait		;; Q.WAIT
	endif
	dw	iosb
	irp	arg,<args>
	ifb	<arg>
	dw	0
	else
	dw	arg		;; Q.P1..P5
	endif
	endm
	endm

QIO$S	macro	func,lun,efn,wait,iosb,args
	local	n
	push	ix
	ld	ix,-QDBSZ
	add	ix,sp
	ld	sp,ix
	ld	(ix+Q.FUNC),low func
	ld	(ix+Q.SUBF),high func
	ld	(ix+Q.LUN),lun
	ld	(ix+Q.EFN),efn
	ifb	<wait>
	ld	(ix+Q.WAIT),0
	else
	ld	(ix+Q.WAIT),wait
	endif
	ld	hl,iosb
	ld	(ix+Q.IOSB),l
	ld	(ix+Q.IOSB+1),h
n	defl	0
	irp	arg,<args>
	ifb	<arg>
	ld	hl,0
	else
	ld	hl,arg
	endif
	ld	(ix+Q.P1+n),l
	ld	(ix+Q.P1+n+1),h
n	defl	n+2
	endm
	push	ix
	pop	hl
	SC	.QIO
	ld	hl,QDBSZ
	add	hl,sp
	ld	sp,hl
	pop	ix
	rlca			;; restore carry bit from error code sign
	rra			;; (works since all errors are negative)
	endm

QIOW$	macro	func,lun,efn,iosb,args
	QIO$	func,lun,efn,1,iosb,<args>
	endm

QIOW$S	macro	func,lun,efn,iosb,args
	QIO$S	func,lun,efn,1,iosb,<args>
	endm

