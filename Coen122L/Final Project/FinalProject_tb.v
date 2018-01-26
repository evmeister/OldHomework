`timescale 1ns / 1ps

// Names:  Evan Eberhardt & James Olwell
// Date:   9 JUN 2017
// File:   Project Test Bench

module FinalProject_tb();
    reg clk;
    wire [31:0] PC;
    wire [31:0] Instr;
    wire regwrt;
    wire [1:0] toreg;
    wire BrN;
    wire BrZ;
    wire J;
    wire JM;
    wire Z;
    wire N;
    wire [2:0] ALUop;
    wire mrd;
    wire mwrt;
    wire [3:0] opcode;
    wire [5:0] rd;
    wire [5:0] rs;
    wire [5:0] rt;
    wire [21:0] X;
    wire [31:0] PC_plus_X;
    wire [31:0] RS_Reg;
    wire [31:0] RT_Reg;
    wire [31:0] DataRead;
    wire Zero;
    wire Negative;
    wire [31:0] ALUout;
    wire [5:0] WriteBackAddress;
    wire [31:0] WriteBackData;
    wire [1:0] PCSource;
    
    CPU test(
        .Clock(clk),
        .PC(PC),
        .Imem_to_IFIDBuffer(Instr),
        .regwrt_to_Rfile(regwrt),
        .toreg_to_mux_1(toreg),
        .BrN_to_PCSource(BrN),
        .BrZ_to_PCSource(BrZ),
        .J_to_PCSource(J),
        .JM_to_PCSource(JM),
        .Z_to_PCSource(Z),
        .N_to_PCSource(N),
        .ALUop_to_ALU(ALUop),
        .mrd_to_Dmem(mrd),
        .mwrt_to_Dmem(mwrt),
        .opcode_to_control(opcode),
        .rd_to_IDEXBuffer(rd),
        .rs_to_Rfile(rs),
        .rt_to_Rfile(rt),
        .X_to_SignExtend(X),
        .Adder_1_to_IDEXBuffer(PC_plus_X),
        .RS_to_Dmem_ALU(RS_Reg),
        .RT_to_Dmem_ALU(RT_Reg),
        .out_to_EXWBBuffer(DataRead),
        .Z_to_EXWBBuffer(Zero),
        .N_to_EXWBBuffer(Negative),
        .sum_to_EXWBBuffer(ALUout),
        .rd_to_Rfile(WriteBackAddress),
        .mux_1_to_Rfile(WriteBackData),
        .PCSource_to_mux_0(PCSource)
    ); 
    
    initial begin
             clk = 0;
             forever #1 clk = ~clk;
             end
             
endmodule