`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Evan Eberhardt
// 
// Create Date: 05/02/2017 02:45:35 PM
// Design Name: Memory
// Module Name: Rfile
// Project Name: Lab 3
//////////////////////////////////////////////////////////////////////////////////


module Rfile(
    input RegWrite,
    input [5:0] RS,
    input [5:0] RT,
    input [5:0] RD,
    input Clock,
    input [31:0] DataIN,
    output reg [31:0] rs_Reg,
    output reg [31:0] rt_Reg
    );
    
    //block
    reg [31:0] rfile [63:0];
    //DEMO
    initial begin
    //List 1
    //rfile[1] = 32'h100;
    //rfile[2] = 8;
    //List 2
    //rfile[1] = 32'h80;
    //rfile[2] = 10;
    //List 3
    //rfile[1] = 32'h40;
    //rfile[2] = 6;
    //List 4
    //rfile[1] = 32'h20;
    //rfile[2] = 12;
    //-------
    
    always @(posedge Clock) begin
    rs_Reg = rfile[RS];
    rt_Reg = rfile[RT];
    
    if(RegWrite == 1)
        rfile[RD] = DataIN;

    end
endmodule
