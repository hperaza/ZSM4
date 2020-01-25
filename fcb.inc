; FCB structure offsets

F.LNK	equ	0		; link to next FCB in list (2 bytes)
F.ATTR	equ	F.LNK + 2	; file attributes and flags (1 byte)
F.DEV	equ	F.ATTR + 1	; device name (2 characters)
F.UNIT	equ	F.DEV + 2	; device unit (1 byte)
F.UCB	equ	F.DEV		; UCB address, shared with dev name (2 bytes)
F.DIR	equ	F.UNIT + 1	; directory name (9 characters)
F.NAME	equ	F.DIR + 9	; file name (9 characters)
F.EXT	equ	F.NAME + 9	; file ext (3 characters)
F.VER	equ	F.EXT + 3	; file version (2 bytes)
F.USER	equ	F.VER + 2	; user code (1 byte)
F.GROUP	equ	F.USER + 1	; group code (1 byte)
F.PROT	equ	F.GROUP + 1	; protection bits (2 bytes)
F.LCNT	equ	F.PROT + 2	; link count (2 bytes)
F.SEQNO	equ	F.LCNT + 2	; sequence number (2 bytes)
F.INODE	equ	F.SEQNO + 2	; index file entry number (2 bytes)
F.NALOC	equ	F.INODE + 2	; total data blocks allocated (2 bytes)
F.NUSED	equ	F.NALOC + 2	; data blocks actually used (2 bytes)
F.LBCNT	equ	F.NUSED + 2	; last block byte count (2 bytes)
F.STABL	equ	F.LBCNT + 2	; starting alloc block number (2 bytes)
F.CALBN	equ	F.STABL + 2	; cached logical alloc block number (2 bytes)
F.CAVBN	equ	F.CALBN + 2	; cached virtual alloc block number (2 bytes)

; Fields present in fileinfo and FDB structures, but not in FCB

F.WAT	equ	F.LNK + 0	; field bit for IO.WAT function (1 byte)
F.WLDC	equ	F.WAT + 1	; wildcards in filespec (1 byte)
F.TCRE	equ	F.STABL + 2	; created timestamp (7 bytes)
F.TMOD	equ	F.TCRE + 7	; last modified timestamp (7 bytes)

; F.ATTR flag bits (for both FCB and index file entries unless otherwise noted)

FA.DIR	equ	80h		; file is a directory
FA.FILE	equ	01h		; file is a regular file
FA.CTG	equ	08h		; file is contiguous
FA.LCK	equ	10h		; file is locked
FA.RD	equ	02h		; file is open for read (FCB only)
FA.WR	equ	04h		; file is open for write (FCB only)
FA.SHR	equ	20h		; file is open in shared mode (FCB only)
FA.MODF	equ	40h		; file has been modified (FCB only)

; F.WAT field bit masks

FA.USER	equ	01h		; set F.USER
FA.GRP	equ	02h		; set F.GROUP
FA.PROT	equ	04h		; set F.PROT
FA.TCRE	equ	10h		; set IE.TCRE
FA.TMOD	equ	20h		; set IE.TMOD

; PFN filespec parsing result bits

FN.DEV	equ	01h		; device name specified
FN.DIR	equ	02h		; directory specified
FN.NAME	equ	04h		; file name specified
FN.EXT	equ	08h		; extension specified
FN.VER	equ	10h		; version specified

; File protection bit masks

FP.R	equ	08h		; read
FP.W	equ	04h		; write
FP.E	equ	02h		; execute (not used)
FP.D	equ	01h		; delete

; Structure sizes

FCBSZ	equ	F.CAVBN + 2	; FCB size
FDBSZ	equ	F.PROT + 2	; size of descriptor used by file open/create, etc.
FNSZ	equ	F.VER + 2	; size of filespec part, used by parsefn
FINFSZ	equ	F.TMOD + 7	; size of fileinfo structure

; Directory entry layout

DE.INDX	equ	0		; index file entry (inode) (2 bytes)
DE.NAME	equ	DE.INDX + 2	; file name (9 characters)
DE.EXT	equ	DE.NAME + 9	; file externsion (3 characters)
DE.VER	equ	DE.EXT + 3	; file version (2 bytes)

DESZ	equ	DE.VER + 2	; directory entry size

; Index file entry (inode) layout

IE.LCNT	equ	0		; link count (2 bytes)
IE.ATTR	equ	IE.LCNT + 2	; file attributes (1 byte)
IE.RES	equ	IE.ATTR + 1	; reserved (1 byte)
IE.SEQN	equ	IE.RES + 1	; file sequence number (2 bytes)
IE.USER	equ	IE.SEQN + 2	; user code (1 byte)
IE.GRP	equ	IE.USER + 1	; group code (1 byte)
IE.STBL	equ	IE.GRP + 1	; starting alloc block number (2 bytes)
IE.ALOC	equ	IE.STBL + 2	; total data blocks allocated (2 bytes)
IE.USED	equ	IE.ALOC + 2	; total data blocks used (2 bytes)
IE.LBCN	equ	IE.USED + 2	; last block byte count (2 bytes)
IE.TCRE	equ	IE.LBCN + 2	; created timestamp (7 bytes)
IE.TMOD	equ	IE.TCRE + 7	; last modified timestamp (7 bytes)
IE.PROT	equ	IE.TMOD + 7	; protection bits (2 bytes)

IESZ	equ	IE.PROT + 2	; index file entry (inode) size

