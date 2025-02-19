
VINCDIR=                                  \
	-I../../rtl/

# synthesis only source files
SYN_SRC=

# simulation only source files
SIM_SRC=                                  \
	system_sim.v                          \
	../../sim/unisims/BUFG.v              \
	../../sim/unisims/DCM_SP.v            \
	../../sim/unisims/FDDRRSE.v           \
	../../sim/ddr/ddr.v                   \

# 
SRC=	                                  \
	system.v                              \
	../../bench/wb_memtest.v              \
	../../bench/lac/lac.v                 \
	../../bench/lac/dp_ram.v              \
	../../bench/lac/uart.v                \
	../../rtl/wb_ddr.v                    \
	../../rtl/ddr_clkgen.v                \
	../../rtl/ddr_pulse78.v               \
	../../rtl/ddr_ctrl.v                  \
	../../rtl/ddr_init.v                  \
	../../rtl/ddr_rpath.v                 \
	../../rtl/ddr_wpath.v                 \
	../../rtl/async_fifo.v                \
	../../rtl/gray_counter.v              \
	../../rtl/rotary.v                    \
	../../rtl/dpram.v                     \

#############################################################################
# Syntheis constants
SYNCLEAN=system.bgn system.drc system.mrp system.ngd system.pcf 
SYNCLEAN+=system.bld system.lso system.ncd system.ngm system.srp
SYNCLEAN+=system.bit system_signalbrowser.* system-routed_pad.tx
SYNCLEAN+=system.map system_summary.xml timing.twr
SYNCLEAN+=system-routed* system_usage* system.ngc param.opt netlist.lst
SYNCLEAN+=xst system.prj

USAGE_DEPTH=0
SMARTGUIDE= 

#############################################################################
# Simulation constants
SIMCLEAN=system_sim.vvp system_sim.vcd verilog.log system_sim.vvp.list

CVER=cver
GTKWAVE=gtkwave
IVERILOG=iverilog
VVP=vvp
	
#############################################################################
# 
sim: system_sim.vcd
syn: system.bit
view: system_sim.view

#############################################################################
# Ikarus verilog simulation

system_sim.vvp: $(SRC) $(SIM_SRC)
	rm -f $@.list
	@for i in `echo $^`; do \
	    echo $$i >> $@.list; \
	done
	$(IVERILOG) -o $@ $(VINCDIR) -c $@.list -s $(@:.vvp=)

%.vcd: %.vvp
	$(VVP) $<

#############################################################################
# ISE Synthesis

system.prj: $(SRC) $(SYN_SRC)
	rm -f system.prj
	@for i in `echo $^`; do \
	    echo "verilog worlk $$i" >> system.prj; \
	done

system.ngc: system.prj
	xst -ifn system.xst

system.ngd: system.ngc system.ucf
	ngdbuild -uc system.ucf system.ngc

system.ncd: system.ngd
	map $(SMARTGUIDE) system.ngd

system-routed.ncd: system.ncd
	par $(SMARTGUIDE) -ol high -w system.ncd system-routed.ncd

system.bit: system-routed.ncd
	bitgen -w system-routed.ncd system.bit

system.mcs: system.bit
	promgen -u 0 system

system-routed.xdl: system-routed.ncd
	xdl -ncd2xdl system-routed.ncd system-routed.xdl

system-routed.twr: system-routed.ncd
	trce -v 10 system-routed.ncd system.pcf

timing: system-routed.twr

usage: system-routed.xdl
	xdlanalyze.pl system-routed.xdl $(USAGE_DEPTH)

####################################################################
# final targets

%.view: %.vcd
	$(GTKWAVE) $< $<.save

clean:
	rm -Rf $(SYNCLEAN) $(SIMCLEAN)

.PHONY: clean view

