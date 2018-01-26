`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Evan Berhardt
// 
// Create Date: 05/09/2017 03:26:11 PM
// Design Name: pipelineBuffer
// Module Name: pipelineBuffer
// Project Name: Lab 4
//////////////////////////////////////////////////////////////////////////////////


module IFIDBuffer(
    input Clock,
    
    input [31:0] inst,
    input [31:0] PC_in,
    
    output reg [31:28] opcode,
    output reg [27:22] rd,
    output reg [21:16] rs,
    output reg [15:10] rt,
    output reg [21:0] X,
    output reg [31:0] PC
    );
    
    always @(posedge Clock) begin
        opcode = inst [31:28];
        rd = inst [27:22];
        rs = inst [21:16];
        rt = inst [15:10];
        X = inst [21:0];
        PC = PC_in;
    end
endmodule

module IDEXBuffer(
    input Clock,
    
    input regwrt_in,
    input [1:0] toreg_in,
    input brn_in,
    input brz_in,
    input J_in,
    input JM_in,
    input ALUop_in,
    input mrd_in,
    input mwrt_in,
    input [5:0] rd_in,
    input [31:0] RS_in,
    input [31:0] RT_in,
    input [31:0] PCplusX,
    
    output reg regwrt,
    output reg [1:0] toreg,
    output reg brn,
    output reg brz,
    output reg J,
    output reg JM,
    output reg ALUop,
    output reg mrd,
    output reg mwrt,
    output reg [5:0] rd,
    output reg [31:0] RS,
    output reg [31:0] RT,
    output reg [31:0] PC    
    );
    
    always @(posedge Clock) begin
        regwrt = regwrt_in;
        toreg = toreg_in;
        brn = brn_in;
        brz = brz_in;
        J = J_in;
        JM = JM_in;
        ALUop = ALUop_in;
        mrd = mrd_in;
        mwrt = mwrt_in;
        rd = rd_in;
        RS = RS_in;
        RT = RT_in;
        PC = PCplusX;
    end
endmodule

module EXWBBuffer (
    input Clock,
    
    input regwrt_in,
    input [1:0] toreg_in,
    input brz_in,
    input brn_in,
    input J_in,
    input JM_in,
    input N_in,
    input Z_in,
    input [31:0] sum_in,
    input [31:0] out_in,
    input [5:0] rd_in,
    input [31:0] PC_in,
    
    output reg regwrt,
    output reg [1:0] toreg,
    output reg brz,
    output reg brn,
    output reg J,
    output reg JM,
    output reg N,
    output reg Z,
    output reg [31:0] sum,
    output reg [31:0] out,
    output reg [5:0] rd,
    output reg PC
    );
    
    always @(posedge Clock) begin
        regwrt = regwrt_in;
        toreg = toreg_in;
        brz = brz_in;
        brn = brn_in;
        J = J_in;
        JM = JM_in;
        N = N_in;
        Z = Z_in;
        sum = sum_in;
        out = out_in;
        rd = rd_in;
        PC = PC_in;
    end
endmodule