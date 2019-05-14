; System function equates

.EXIT	equ	0	; exit program
.EMTST	equ	1	; emit status
.QIO	equ	2	; queue I/O packet
.CONN	equ	3	; connect to task
.GTCMD	equ	4	; get command line arguments
.SEND	equ	5	; send data
.RECV	equ	6	; receive data
.WTDAT	equ	7	; wait for data
.ASTDF	equ	8	; declare AST service routine
.ASTCT	equ	9	; AST control (enable/disable AST types)
.ASTX	equ	10	; exit AST service routine
.ALUN	equ	11	; assign LUN to device
.GTLUN	equ	12	; get LUN information
.GDIR	equ	13	; get current dir name
.SDIR	equ	14	; set current dir
.GDAT	equ	15	; get date and time
.SDAT	equ	16	; set date and time
.RQST	equ	17	; request installed task
.RPOI	equ	18	; request and pass offspring information
.ABORT	equ	19	; abort a task
.STOP	equ	20	; stop task
.RESUM	equ	21	; resume task
.CLRFL	equ	22	; clear event flag
.SETFL	equ	23	; set event flag
.RDFLG	equ	24	; read event flag
.WTFLG	equ	25	; wait for event flag
.RUN	equ	26	; request installed task at specified time
.CSRQ	equ	27	; cancel scheduled task request
.MRKT	equ	28	; mark time request
.CMKT	equ	29	; cancel mark time request
.EXTSK	equ	30	; extend task size
.ALTPR	equ	31	; change task priority
.SUPER	equ	32	; enter/exit supervisor mode
.GTSK	equ	33	; get task info
.GTPAR	equ	34	; get partition info
.GIN	equ	35	; get general info

MAXFN	equ	35

SYSRST	equ	20h	; system call RST is RST 4
DBGRST	equ	30h	; debug breakpoint RST is RST 6

; .GIN subfunction codes

I.VERS	equ	0	; get system version
I.SMEM	equ	1	; get system memory info
I.USCB	equ	2	; get user's SCB
I.TSCB	equ	3	; get SCB of terminal device
I.HOST	equ	4	; get host name

; Macro to call system services

SC	MACRO	func
	rst	SYSRST
	db	func
	ENDM

