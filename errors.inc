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
E.NOBUF	equ	-14	; Out of disk buffers
E.DEVNM	equ	-15	; Device not mounted
E.DEVAM	equ	-16	; Device already mounted
E.DMOP	equ	-17	; Dismount in progress
E.OFL	equ	-18	; Unit offline
E.BADVT	equ	-19	; Invalid volume type
E.UNA	equ	-20	; Reading unallocated block (unwritten data)
E.FLCK	equ	-21	; File access is locked
E.NODEV	equ	-22	; No such device
E.EXIST	equ	-23	; File exists
E.DNE	equ	-24	; Directory not empty
E.VLIM	equ	-25	; File version limit reached
E.BADFN	equ	-26	; Invalid system call
E.BADTH	equ	-27	; Invalid task header
E.TCKS	equ	-28	; Task image checksum error
E.BADTF	equ	-29	; Invalid or corrupt task image file
E.TNF	equ	-30	; Task not found
E.TNU	equ	-31	; Task name in use
E.FNC	equ	-32	; File not contiguous
E.NCSPC	equ	-33	; No contiguous space on device
E.NOMEM	equ	-34	; Not enough room
E.PEND	equ	-35	; I/O request pending
E.TRUN	equ	-36	; Task already running
E.TSTP	equ	-37	; Task already stopped
E.TDLY	equ	-38	; Task already delayed
E.TFIX	equ	-39	; Task already fixed
E.TNFIX	equ	-40	; Task not fixed
E.TACT	equ	-41	; Task active
E.TNAC	equ	-42	; Task not active
E.TNIU	equ	-43	; Task name in use
E.TABO	equ	-44	; Task abort in progress
E.FAIL	equ	-45	; Operation failed
E.ABOP	equ	-46	; Operation aborted
E.TMO	equ	-47	; Operation timed out
E.PRIV	equ	-48	; Privileged command
E.PBIG	equ	-49	; Program too big
E.QEMP	equ	-50	; Queue empty
E.BADFL	equ	-51	; Invalid flag number
E.PBSY	equ	-52	; Partition busy
E.PNF	equ	-53	; Partition not found
E.SSNF	equ	-54	; Session not found
E.SSNA	equ	-55	; Session not active
E.DMOI	equ	-56	;- Dismount initiated
E.NLI	equ	-57	;- Not logged in
E.ULI	equ	-58	;- Already (Other user) logged in

; Task exit status codes (lo-byte, hi-byte is reserved for user codes)

EX.WRN	equ	0	; Warning
EX.SUC	equ	1	; Success
EX.ERR	equ	2	; Error
EX.SEV	equ	4	; Severe

