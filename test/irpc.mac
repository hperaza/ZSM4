	cseg

	irpc	a,1234567890
	db	a+1
	endm

	irpc	a,<123456>
	db	a
	endm

	irpc	a,<12345,67890>	; expansion must include the comma
	db	'&a'
	endm

	irpc	a,<>		; null arg is permissible
	db	'&a'
	endm

	irpc	a,12345678
	db	a+1		; this comment should appear in the expansion
	db	a+2		;; but not this one
	endm

	irpc	a,<12<3>>	; nested <>s
	db	'&a'
	endm

	end
