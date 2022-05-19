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
E.INV	equ	-13	; Invalid value
E.LUN	equ	-14	; Invalid LUN
E.NOBUF	equ	-15	; Out of disk buffers
E.DEVNM	equ	-16	; Device not mounted
E.DEVAM	equ	-17	; Device already mounted
E.DMOP	equ	-18	; Dismount in progress
E.OFL	equ	-19	; Unit offline
E.BADVT	equ	-20	; Invalid volume type
E.UNA	equ	-21	; Reading unallocated block (unwritten data)
E.FLCK	equ	-22	; File access is locked
E.NODEV	equ	-23	; No such device
E.EXIST	equ	-24	; File exists
E.DNE	equ	-25	; Directory not empty
E.VLIM	equ	-26	; File version limit reached
E.BADFN	equ	-27	; Invalid system call
E.BADTH	equ	-28	; Invalid task header
E.TCKS	equ	-29	; Task image checksum error
E.BADTF	equ	-30	; Invalid or corrupt task image file
E.TNF	equ	-31	; Task not found
E.TNU	equ	-32	; Task name in use
E.FNC	equ	-33	; File not contiguous
E.NCSPC	equ	-34	; No contiguous space on device
E.NOMEM	equ	-35	; Not enough room
E.PEND	equ	-36	; I/O request pending
E.TRUN	equ	-37	; Task already running
E.TSTP	equ	-38	; Task already stopped
E.TDLY	equ	-39	; Task already delayed
E.TFIX	equ	-40	; Task already fixed
E.TNFIX	equ	-41	; Task not fixed
E.TACT	equ	-42	; Task active
E.TNAC	equ	-43	; Task not active
E.TNIU	equ	-44	; Task name in use
E.TABO	equ	-45	; Task abort in progress
E.FAIL	equ	-46	; Operation failed
E.ABOP	equ	-47	; Operation aborted
E.TMO	equ	-48	; Operation timed out
E.PRIV	equ	-49	; Privileged command
E.PBIG	equ	-50	; Program too big
E.QEMP	equ	-51	; Queue empty
E.BADFL	equ	-52	; Invalid flag number
E.PBSY	equ	-53	; Partition busy
E.PNF	equ	-54	; Partition not found
E.SSNF	equ	-55	; Session not found
E.SSNA	equ	-56	; Session not active
E.CLNF	equ	-57	;- CLI not found
E.DMOI	equ	-58	;- Dismount initiated
E.NLI	equ	-59	;- Not logged in
E.ULI	equ	-60	;- Already (Other user) logged in

; Task exit status codes (lo-byte, hi-byte is reserved for user codes)

EX.WRN	equ	0	; Warning
EX.SUC	equ	1	; Success
EX.ERR	equ	2	; Error
EX.SEV	equ	4	; Severe

