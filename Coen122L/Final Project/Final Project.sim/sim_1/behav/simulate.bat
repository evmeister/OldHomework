@echo off
set xv_path=C:\\Apps\\Xilinx\\Vivado\\2016.2\\bin
call %xv_path%/xsim FinalProject_tb_behav -key {Behavioral:sim_1:Functional:FinalProject_tb} -tclbatch FinalProject_tb.tcl -view C:/Users/eeberhar/Coen122L/Final Project/FinalProject_tb_behav.wcfg -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
