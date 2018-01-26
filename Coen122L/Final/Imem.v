`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Evan Eberahrdt
// 
// Create Date: 05/02/2017 02:45:35 PM
// Design Name: Memory
// Module Name: Imem
// Project Name: Lab 3
//////////////////////////////////////////////////////////////////////////////////

module Imem(
    input [31:0] PC_addr,
    input Clock,
    output reg [31:0] Instruction
    );

    reg [31:0] imem[255:0];
    
    initial
    imem[200] = 1028;
        
    always @(posedge Clock) begin
    Instruction = imem[PC_addr];
    
    end
    
endmodule
