# Path to Linux utilities
ZXCC   = zxcc

# Path to CP/M utilities
ZSM4   = ../../Tools/cpm/zsm4.com
DRLINK = ../../Tools/cpm/drlink.com
TKB    = ../../Tools/cpm/tkb.com

.PREFIX:
.PREFIX: .mac .rel

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
	$(ZXCC) $(ZSM4) -"=$</l"

_zsm4.com: $(OBJS)
	$(ZXCC) $(DRLINK) -"_zsm4=zsm,symbols,listing,alloc,eval,macros,genrel,cpmio"

mac.tsk: $(OBJS) syslib.lib fcslib.lib
	@echo -e "mac,mac,mac=zsm/of:tsk,symbols,listing,alloc,eval,macros,genrel,rsxio,&\r" > build.cmd
	@echo -e "fcslib/lb,syslib/lb/task=...MAC/ext=8000/asg=TI:5,SY:1-4:6-11\r" >> build.cmd
	$(ZXCC) $(TKB) -"@build"
	@rm build.cmd

selftest: _zsm4.com
	$(ZXCC) _zsm4 -"_z=zsm/l/s7"
	$(ZXCC) _zsm4 -"_s=symbols/l/s7"
	$(ZXCC) _zsm4 -"_l=listing/l/s7"
	$(ZXCC) _zsm4 -"_a=alloc/l/s7"
	$(ZXCC) _zsm4 -"_e=eval/l/s7"
	$(ZXCC) _zsm4 -"_m=macros/l/s7"
	$(ZXCC) _zsm4 -"_r=genrel/l/s7"
	$(ZXCC) _zsm4 -"_c=cpmio/l/s7"
	$(ZXCC) $(DRLINK) -"_z=_z,_s,_l,_a,_e,_m,_r,_c"
	rm -f _*.rel
	comp _z.com _zsm4.com > comp_z_zsm4
	ls -l comp_z_zsm4

clean:
	rm -f _zsm4.com mac.tsk *.rel *.sym *.prn *.crf *.map *.dmp core *~ *.\$$\$$\$$
	rm -f _z.com comp_z_zsm4
