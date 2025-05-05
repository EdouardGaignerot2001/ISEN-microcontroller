transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {C:/Users/gilda/Desktop/Cours/ISEN/Elec/TPs-AP4/TP_FPGA/TP1_additionneur/half_adder.vhd}
vcom -93 -work work {C:/Users/gilda/Desktop/Cours/ISEN/Elec/TPs-AP4/TP_FPGA/TP1_additionneur/full_adder_4b.vhd}
vcom -93 -work work {C:/Users/gilda/Desktop/Cours/ISEN/Elec/TPs-AP4/TP_FPGA/TP1_additionneur/toplevel.vhd}
vcom -93 -work work {C:/Users/gilda/Desktop/Cours/ISEN/Elec/TPs-AP4/TP_FPGA/TP1_additionneur/full_adder.vhd}

vcom -93 -work work {C:/Users/gilda/Desktop/Cours/ISEN/Elec/TPs-AP4/TP_FPGA/TP1_additionneur/tb_full_adder_4b.vhd}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cyclonev -L cyclonev_hssi -L rtl_work -L work -voptargs="+acc"  tb_full_adder_4b

add wave *
view structure
view signals
run -all
