`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Evan Eberhardt
// 
// Create Date: 05/02/2017 02:45:35 PM
// Design Name: Memory
// Module Name: Dmem
// Project Name: Lab 3
//////////////////////////////////////////////////////////////////////////////////


module Dmem(
    input Clock,
    input MemWrite,
    input MemRead,
    input [31:0] DataAddr,
    input [31:0] DataIN,
    output reg [31:0] DataRead
    );
    
    //block
    reg [31:0] dmem [65536:0];
    //DEMO
    //initial begin
    //$readmemh("C:\Users\eeberhar\Coen122L\Final Project\DemoNumbers.txt", dmem);
    //end
    //-----
    
    always @(posedge Clock) begin
    if(MemWrite == 1)
        dmem[DataAddr] = DataIN;
    else if(MemRead == 1)
        DataRead = dmem[DataAddr];
        
    end
endmodule
