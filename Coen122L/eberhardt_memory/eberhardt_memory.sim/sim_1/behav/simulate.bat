@echo off
set xv_path=C:\\Apps\\Xilinx\\Vivado\\2016.2\\bin
call %xv_path%/xsim memory_testbench_behav -key {Behavioral:sim_1:Functional:memory_testbench} -tclbatch memory_testbench.tcl -view C:/Users/eeberhar/eberhardt_memory/memory_testbench_behav.wcfg -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
