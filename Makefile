.PREFIX:
.PREFIX: .mac .rel

MKTASK = ../../Tools/linux/mktask/mktask

SRCS = zsm.mac \
	symbols.mac \
	listing.mac \
	alloc.mac \
	eval.mac \
	macros.mac \
	genrel.mac \
	cpmio.mac \
	rsxio.mac

OBJS = $(SRCS:.mac=.rel)

all: _zsm4.com mac.tsk

$(OBJS): %.rel: %.mac *.inc
	zxcc m80 -"=$</l/z"

_zsm4.com: $(OBJS)
	zxcc drlink -"_zsm4=zsm,symbols,listing,alloc,eval,macros,genrel,cpmio"

mac.bin: $(OBJS) syslib.lib fcslib.lib
	zxcc drlink -"mac.bin=zsm,symbols,listing,alloc,eval,macros,genrel,rsxio,fcslib.lib[s],syslib.lib[s]"

mac.tsk: mac.bin
	$(MKTASK) $< -o $@ -name "...MAC" -id "ZSM4.1" -inc 8000 -asg "TI:5,SY:1-4:6-11"

selftest: _zsm4.com
	zxcc _zsm4 -"_z=zsm/l/s7"
	zxcc _zsm4 -"_s=symbols/l/s7"
	zxcc _zsm4 -"_l=listing/l/s7"
	zxcc _zsm4 -"_a=alloc/l/s7"
	zxcc _zsm4 -"_e=eval/l/s7"
	zxcc _zsm4 -"_m=macros/l/s7"
	zxcc _zsm4 -"_r=genrel/l/s7"
	zxcc _zsm4 -"_c=cpmio/l/s7"
	zxcc drlink -"_z=_z,_s,_l,_a,_e,_m,_r,_c"
	rm -f _*.rel
	comp _z.com _zsm4.com > comp_z_zsm4
	ls -l comp_z_zsm4

clean:
	rm -f _zsm4.com mac.bin mac.tsk *.rel *.sym *.prn *.crf *.dmp core *~ *.\$$\$$\$$
	rm -f _z.com comp_z_zsm4
