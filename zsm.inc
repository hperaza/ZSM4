FALSE	equ	0		; fiction
TRUE	equ	NOT FALSE	; stranger than fiction

VER	equ	47		; version number

VER1	equ	VER/10+'0'	; most significant version digit
VER2	equ	VER MOD 10+'0'	; least significant version digit

CR	equ	13
LF	equ	10
TAB	equ	9
EOF	equ	1Ah

DEFLNP	equ	60		; default lines per page, including
				;  header, title and subtitle lines

RECMAX	equ	160		; size of the input line buffer
IDMAX	equ	15		; max identifier length, must be < 16

LNGERR	equ	FALSE		; long error messages

;HDRSZ	equ	24
HDRSZ	equ	32		; min 24, must be a multiple of 8

OSTKSZ	equ	16		; size of operand and operator stacks
CSTKSZ	equ	10		; size of conditionals stack

; Symbol types (upper nibble of length field)

RNAME	equ	10h		; register name
RPNAME	equ	20h		; register pair name
RSNAME	equ	30h		; special register name
COND	equ	40h		; jump/return conditional name
EQUNAME	equ	50h		; EQUate label name
DFLNAME	equ	60h		; DEFL label name
COMNAME	equ	70h		; COMMON name
MULTDEF	equ	80h		; multiple-defined label or equate

; Symbol modes (bit masks)

DSGSYM	equ	080h		; symbol in data segment
CSGSYM	equ	040h		; symbol in code segment
CMNSYM	equ	0C0h		; symbol in COMMON segment
EXTSYM	equ	010h		; external reference
GBLSYM	equ	020h		; public symbol
UNDEF	equ	001h		; undefined symbol

; List options (bit numbers)

LISTFL	equ	0		; set if we want a listing
CONDFL	equ	1		; set if we want false conditionals
SYMBLS	equ	2		; set if we want a symbol table
SORTFL	equ	3		; set if we want sorted symbol table
MACRFL	equ	4		; set if we want full macro expansions
XMACFL	equ	5		; set if we want to list only macro lines
				;  that generate object code

; Opcode flags - CPU type

Z80	equ	00h
Z180	equ	10h
Z280	equ	20h

; Type of structures pushed on the dynamic storage stack

STINPF	equ	1		; include/input file state
STMDEF	equ	2		; macro definition
STMEXP	equ	3		; macro expansion/execution
STMBLD	equ	4		; macro build context (for nested macros)
STDEL	equ	0FFh		; deleted entry, awaiting garbage collection

