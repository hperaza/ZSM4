; System error codes

E.OK	equ	0	; No error
E.EOF	equ	-1	; End of file
E.FNF	equ	-2	; File not found
E.DNF	equ	-3	; Directory not found
E.NODIR	equ	-4	; Not a directory
E.BADF	equ	-5	; Bad file specification
E.DSKF	equ	-6	; Disk full
E.IDXF	equ	-7	; Index file full
E.IDXE	equ	-8	; Index file error
E.BADOP	equ	-9	; Invalid operation
E.CHOPN	equ	-10	; Channel already in use
E.IO	equ	-11	; Channel I/O error
E.PERM	equ	-12	; Access denied
E.INV	equ	-13	; Invalid value (FCB/LUN)
E.NOFCB	equ	-14	; Not enough memory for new FCB
E.NOBUF	equ	-15	; No free disk buffers available
E.DEVNM	equ	-16	; Device not mounted
E.DEVAM	equ	-17	; Device already mounted
E.OFL	equ	-18	; Unit offline
E.BADVT	equ	-19	; Invalid volume type
E.UNA	equ	-20	; Reading unallocated block (unwritten data)
E.FLCK	equ	-21	; File access is locked
E.NODEV	equ	-22	; No such device
E.EXIST	equ	-23	; File exists
E.DNE	equ	-24	; Directory not empty
E.BADFN	equ	-25	; Invalid system call
E.BADTH	equ	-26	; Invalid task header
E.TCKS	equ	-27	; Task image checksum error
E.BADTF	equ	-28	; Invalid or corrupt task image file
E.TNF	equ	-29	; Task not found
E.TNU	equ	-30	; Task name in use
E.FNC	equ	-31	; File not contiguous
E.NCSPC	equ	-32	; No contiguous space on device
E.NOMEM	equ	-33	; Not enough room
E.TRUN	equ	-34	; Task already running
E.TSTP	equ	-35	; Task already stopped
E.TDLY	equ	-36	; Task already delayed
E.TFIX	equ	-37	; Task already fixed
E.TNFIX	equ	-38	; Task not fixed
E.TACT	equ	-39	; Task active
E.TNAC	equ	-40	; Task not active
E.TNIU	equ	-41	; Task name in use
E.FAIL	equ	-42	; Operation failed
E.ABOP	equ	-43	; Operation aborted
E.TMO	equ	-44	; Operation timed out
E.PRIV	equ	-45	; Privileged command
E.PBIG	equ	-46	; Program too big
E.QEMP	equ	-47	; Queue empty
E.BADFL	equ	-48	; Invalid flag number
E.PBSY	equ	-49	; Partition busy
E.PNF	equ	-50	; Partition not found
E.SSNF	equ	-51	; Session not found
E.SSNA	equ	-52	; Session not active
E.NLI	equ	-53	; Not logged in
E.ULI	equ	-54	; Already (Other user) logged in

; Task exit status codes (lo-byte, hi-byte is reserved for user codes)

EX.WRN	equ	0	; Warning
EX.SUC	equ	1	; Success
EX.ERR	equ	2	; Error
EX.SEV	equ	4	; Severe

