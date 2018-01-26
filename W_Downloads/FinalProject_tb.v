`timescale 1ns / 1ps

// Names:  Evan Eberhardt & James Olwell
// Date:   9 JUN 2017
// File:   Project Test Bench

module FinalProject_tb():
    reg clk;
    wire PC [31:0];
    wire Instruction [31:0];
    wire regwrt;
    wire [1:0] toreg;
    wire BrN;
    wire BrZ;
    wire J;
    wire JM;
    wire [2:0] ALUop;
    wire mrd;
    wire mwrt;
    wire [31:28] opcode;
    wire [27:22] rd;
    wire [21:16] rs;
    wire [15:10] rt;
    wire [21:0] X;
    wire [31:0] XOut;
    wire [31:0] RS_Reg;
    wire [31:0] RT_Reg;
    wire [31:0] DataRead;
    wire Z;
    wire N;
    wire [31:0] ALUout;
    wire [31:0] DataIn;
    wire [31:0] PCout;
    wire [1:0] SourceOut;
    
    CPU test(
        .Clock(clk),
        .PC(PC),
        .Imem_to_IFIDBuffer(Instruction),
        .(regwrt),
        .(toreg),
        .(BrN),
        .(BrZ),
        .(J),
        .(JM),
        .(ALUop),
        .(mrd),
        .(mwrt),
        .opcode_to_control(opcode),
        .(rd),
        .(rs),
        .(rt),
        .(X),
        .(XOut),
        .(RS_Reg),
        .(RT_Reg),
        .(DataRead),
        .(Z),
        .(N),
        .(ALUout),
        .(DataIn),
        .(PCout),
        .(SourceOut)
    ); 
    
    initial begin
             clk = 0;
             forever #5 clk = ~clk;
             end
             
endmodule