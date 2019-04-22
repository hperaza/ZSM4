.PREFIX:
.PREFIX: .mac .rel .prn

SRCS = 128.mac \
	asegtst.mac \
	cconst.mac \
	comment.mac \
	common1.mac \
	common2.mac \
	common3.mac \
	common.mac \
	defz.mac \
	dseg0.mac \
	dszero.mac \
	even.mac \
	expr2.mac \
	expr.mac \
	exttest1.mac \
	exttest2.mac \
	exttest3.mac \
	exttest4.mac \
	exttest.mac \
	ident.mac \
	iext.mac \
	ifbnb.mac \
	ifdef.mac \
	ifidndif.mac \
	iftest.mac \
	incl01.mac \
	incl02.mac \
	incl0.mac \
	irp1.mac \
	irpc.mac \
	irp.mac \
	ldwtest.mac \
	lesstest.mac \
	local1.mac \
	local2.mac \
	local.mac \
	macro0.mac \
	macro10a.mac \
	macro10.mac \
	macro11.mac \
	macro12.mac \
	macro13.mac \
	macro14.mac \
	macro16.mac \
	macro17.mac \
	macro1a.mac \
	macro1.mac \
	macro20.mac \
	macro21.mac \
	macro22.mac \
	macro24.mac \
	macro25.mac \
	macro26.mac \
	macro27.mac \
	macro28.mac \
	macro2.mac \
	macro3a.mac \
	macro3.mac \
	macro4.mac \
	macro5.mac \
	macro6.mac \
	macro7.mac \
	macro8.mac \
	macro9.mac \
	nultest.mac \
	phase.mac \
	pp.mac \
	ra280.mac \
	radix.mac \
	reltest.mac \
	rept1.mac \
	rept.mac \
	rqst.mac \
	segtest.mac \
	symtest.mac \
	test1.mac \
	test2a.mac \
	test2.mac \
	test3.mac \
	test4.mac \
	test5.mac \
	test816.mac \
	testz80.mac \
	xx1.mac \
	xx2.mac \
	xx.mac \
	z180test.mac \
	z280test.mac \
	z80test2.mac \
	z80test.mac \
	zsmtest.mac

PRNS = $(SRCS:.mac=.prn)

all: $(PRNS)

$(PRNS): %.prn: %.mac *.inc
	zxcc ../_zsm4 -"=$</l"

clean:
	rm -f *.rel *.sym *.prn *.crf *.dmp core *~ *.\$$\$$\$$
