	cseg

	irp	a,<1,2,3,4,5,6,7,8,9,0>
	db	a+1
	endm

	irp	a,<123456>
	db	'&a'
	endm

	irp	a,<12345 67890>
	db	'&a'
	endm

	irp	a,<12345,67890>
	db	'&a'
	endm

	irp	a,<>		; null arg is permissible
	db	'&a'
	endm

	irp	a,<1,,2>
	db	'&a'
	endm

	irp	a,<1,2,3,4,5,6,7,8>
	db	a+1		; this comment should appear in the expansion
	db	a+2		;; but not this one
	endm

	irp	a,<1,<,2,>,>
	db	'&a'
	endm

	end
