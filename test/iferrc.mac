; Test of IF error code not appearing on error line

a	equ	1
z	equ	0

	IF	a
	ld	a,1
	ELSE
	ld	a,2
	ENDIF

	IF	b		; 'U' error
	ld	a,1
	ELSE
	ld	a,2
	ENDIF

	IF	a
	IF	b		; 'U' error
	ld	a,1
	ELSE
	ld	a,2
	ENDIF
	ENDIF

	IF	b		; 'U' error
	IF	a
	ld	a,1
	ELSE
	ld	a,2
	ENDIF
	ENDIF

	IF	b		; 'U' error
	IF	b		; no 'U' error
	ld	a,1
	ELSE
	ld	a,2
	ENDIF
	ENDIF

	IF	z
	IF	b		; no 'U' error
	ld	a,1
	ELSE
	ld	a,2
	ENDIF
	ENDIF

	END
