; Note: include FCB.INC before this file.

; GCML structure

G.BUF	equ	0		; address of command buffer (2 bytes)
G.SIZE	equ	G.BUF + 2	; size of buffer (1 byte)
G.LEN	equ	G.SIZE + 1	; number of valid chars in buffer (1 byte)
G.PRM	equ	G.LEN + 1	; pointer to prompt string (2 bytes)
G.LUN	equ	G.PRM + 2	; LUN used for terminal and file I/O (1 byte)
G.MAXD	equ	G.LUN + 1	; max nesting depth (1 byte)
G.MODE	equ	G.MAXD + 1	; mode bits (1 byte)
G.ST	equ	G.MODE + 1	; status, used internally (1 byte)
G.ERR	equ	G.ST + 1	; error code (1 byte)
G.LVL	equ	G.ERR + 1	; current nesting level (1 byte)
G.IFN	equ	G.LVL + 1	; name of current indirect file (FNSZ bytes)
G.DEVC	equ	G.IFN + FNSZ	; device capabilities (1 byte)
G.LN	equ	G.DEVC + 1	; current line # in indirect file (2 bytes)
G.PDL	equ	G.LN + 2	; address of push-down list area (2 bytes)

; GCML push-down list item size

PDLSZ	equ	FNSZ + 6

; GCML mode bits

GM.ELN	equ	0		; if set, return empty lines
GM.CMT	equ	1		; if set, do not return comment lines
GM.ICF	equ	2		; if set, disable recognition of @cmdfiles

; GCML status bits

GS.EOF	equ	0		; if set, no more commands are available
GS.MCR	equ	1		; set once the MCR command line is processed
GS.INT	equ	2		; set if in interactive (prompt) mode
GS.FIL	equ	3		; set if last command came from a file

; GCML-specific error codes

GE.OK	equ	0		; success
GE.SN	equ	1		; syntax error in command file specification
GE.LEN	equ	2		; line too long in command file
GE.NLV	equ	3		; command nesting level too deep

; Macro to generate a GCML structure

GCML$	MACRO	buf,siz,prm,lun,maxd,pdl
	local	lbuf,lprm,lpdl
	ifnb	<buf>
	dw	buf		;; G.BUF
	else
	dw	lbuf
	endif
	db	siz		;; G.SIZ
	ds	1		;; G.LEN
	dw	lprm		;; G.PRM
	db	lun		;; G.LUN
	db	maxd		;; G.MAXD
	db	0,0,0,0		;; G.MODE, G.STAT, G.ERR, G.LVL
	ds	FNSZ		;; G.IFN
	ds	1		;; G.DEVC
	ds	2		;; G.LN
	ifnb	<pdl>
	dw	pdl		;; G.PDL
	else
	dw	lpdl
	endif
	ifb	<buf>
lbuf:	ds	siz+2
	endif
lprm:	db	0Dh,0Ah,prm,'>',0
	ifb	<pdl>
lpdl:	ds	maxd*PDLSZ
	endif
	ENDM

