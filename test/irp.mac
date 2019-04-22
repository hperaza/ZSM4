	cseg

	irp	a,<1,2,3,4,5,6,7,8,9,0>
	db	a+1
	endm

	irp	a,<12345>
	dw	a
	endm

	irp	a,<12345 6789>
	dw	a+1
	endm

	irp	a,<12345,67890>
	db	'&a'
	endm

	irp	a,<>		; null arg
	db	'&a'
	endm

	end
