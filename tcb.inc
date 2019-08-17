; Task Control Block structure

T.LNK	equ	0		; link to next TCB in priority list (2 bytes)
T.TCBL	equ	T.LNK + 2	; link to next TCB in directory list (2 bytes)
T.ATTR	equ	T.TCBL + 2	; attributes (1 byte)
T.ST	equ	T.ATTR + 1	; status (1 byte)
T.DPRI	equ	T.ST + 1	; default priority (1 byte)
T.PRI	equ	T.DPRI + 1	; current priority (1 byte)
T.NAME	equ	T.PRI + 1	; task name (6 characters)
T.VID	equ	T.NAME + 6	; task version identification (6 characters)
T.CMD	equ	T.VID + 6	; pointer to command line block (2 bytes)
T.IOC	equ	T.CMD + 2	; outstanding I/O count (1 byte)
T.RCVL	equ	T.IOC + 1	; pointer to receive queue (2 bytes)
T.OCBL	equ	T.RCVL + 2	; pointer to list of OCBs (2 bytes)
T.ASTL	equ	T.OCBL + 2	; pointer to list of AST events (2 bytes)
T.AST	equ	T.ASTL + 2	; AST handler routine address (2 bytes)
T.ASTP	equ	T.AST + 2	; AST parameter block address (2 bytes)
T.SAST	equ	T.ASTP + 2	; specified ASTs bit mask (1 byte)
T.SVST	equ	T.SAST + 1	; saved task status during AST (1 byte)
T.FLGS	equ	T.SVST + 1	; task event flags (4 bytes = 32 flags)
T.WAIT	equ	T.FLGS + 4	; flag wait mask (4 bytes)
T.CTX	equ	T.WAIT + 4	; pointer to Context Block (2 bytes)
T.TI	equ	T.CTX + 2	; UCB of terminal device (2 bytes)
T.CON	equ	T.TI + 2	; console device and unit (3 bytes)
T.LD	equ	T.CON + 3	; UCB of load device (2 bytes)
T.LIB	equ	T.LD + 2	; task load device and unit (3 bytes)
T.SBLK	equ	T.LIB + 3	; task starting disk block number (4 bytes)
T.NBLK	equ	T.SBLK + 4	; task size in disk blocks (2 bytes)
T.PCB	equ	T.NBLK + 2	; pointer to PCB (2 bytes)
T.STRT	equ	T.PCB + 2	; start address (2 bytes)
T.DEND	equ	T.STRT + 2	; default end address (2 bytes)
T.END	equ	T.DEND + 2	; current end address (2 bytes)
T.EPT	equ	T.END + 2	; entry point (2 bytes)
T.SP	equ	T.EPT + 2	; task SP (2 bytes)

; TCB size

TCBSZ	equ	T.SP + 2

; Attribute bit numbers

TA.PRV	equ	0		; task is privileged
TA.REM	equ	1		; remove on exit
TA.AST	equ	2		; AST recognition enabled
TA.FIX	equ	3		; task fixed in memory
TA.MCR	equ	4		; task is external MCR function
TA.CLI	equ	5		; task is a CLI
TA.ACP	equ	6		; task is an ACP

; Status bit numbers

TS.ACT	equ	0		; task active
TS.STP	equ	1		; stopped
TS.IOW	equ	2		; I/O waiting / flag waiting
TS.WTD	equ	3		; waiting for data
TS.AST	equ	4		; task is executing an AST
TS.SUP	equ	5		; task is in supervisor mode
TS.OUT	equ	6		; task is out of memory

; Mask for task running bits

TM.RUN	equ	(1 SHL TS.STP) OR (1 SHL TS.IOW) OR (1 SHL TS.WTD) OR (1 SHL TS.OUT)

; Task Context Block structure

TX.UID	equ	0		; protection user ID (1 byte)
TX.GID	equ	TX.UID + 1	; protection group ID (1 byte)
TX.DIR	equ	TX.GID + 1	; task's current directory (9 bytes)
TX.PC	equ	TX.DIR + 9	; saved PC during AST execution (2 bytes)
TX.SWM	equ	TX.PC + 2	; saved flag wait mask during AST (4 bytes)
TX.LUT	equ	TX.SWM + 4	; LUN translation table (64 bytes)

; Context Block size

CTXSZ	equ	TX.LUT + 64

; Task Descriptor Block

TD.NAME	equ	0		; task name (6 characters)
TD.CMD	equ	TD.NAME + 6	; address of command line block (2 bytes)
TD.CML	equ	TD.CMD + 2	; length of command (2 bytes)
TD.ATTR	equ	TD.CML + 2	; initial attributes (1 byte)
TD.USR	equ	TD.ATTR + 1	; user number (1 byte)
TD.GRP	equ	TD.USR + 1	; group number (1 byte)
TD.CON	equ	TD.GRP + 1	; console device and unit (3 bytes)
TD.SDAT	equ	TD.CON + 3	; address of data block to send (2 bytes)
TD.SLEN	equ	TD.SDAT + 2	; size of data block to send (2 bytes)

; TDB size

TDBSZ	equ	TD.SLEN + 2

; Offspring Control Block

O.LNK	equ	0		; link to next OCB in list (2 bytes)
O.PTCB	equ	O.LNK + 2	; address of parent's TCB (2 bytes)
O.EFN	equ	O.PTCB + 2	; event flag number (1 byte)
O.ESB	equ	O.EFN + 1	; addr of parent's exit status block (2 bytes)
O.ST	equ	O.ESB + 2	; status (2 bytes)

; OCB size

OCBSZ	equ	O.ST + 2

