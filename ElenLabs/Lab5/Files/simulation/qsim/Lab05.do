onerror {quit -f}
vlib work
vlog -work work Lab05.vo
vlog -work work Lab05.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.parta_vlg_vec_tst
vcd file -direction Lab05.msim.vcd
vcd add -internal parta_vlg_vec_tst/*
vcd add -internal parta_vlg_vec_tst/i1/*
add wave /*
run -all
