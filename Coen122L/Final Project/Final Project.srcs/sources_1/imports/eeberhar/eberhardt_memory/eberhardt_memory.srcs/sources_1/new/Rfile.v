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
    initial begin rs_Reg = 0; rt_Reg = 0;
    rfile[3] = 0;
    rfile[4] = 0;
    
    //TEST
    //*
    rfile[11] = 11;
    rfile[12] = 12;
    rfile[14] = 14;
    rfile[15] = 15;
    rfile[17] = 17;
    rfile[20] = 20;
    rfile[23] = 23;
    rfile[24] = 24;
    rfile[18] = 21;
    rfile[28] = 28;
    rfile[30] = 28;
    rfile[34] = 34;
    rfile[33] = 33;
    rfile[35] = 39;
    rfile[36] = 39;
    rfile[9] = 9;
    rfile[10] = 10;
    rfile[38] = 46;
    rfile[44] = 44;
    rfile[43] = 43;
    rfile[46] = 0;
    // */  
    
    
    //Array 1 = 1879048192
    //rfile[1] = 32'h00000100;
    //rfile[2] = 8;
    //Array 2 = 3722304989
    //rfile[1] = 32'h00000080;
    //rfile[2] = 10;
    //Array 3 = 1431655765
    rfile[1] = 32'h00000040;
    rfile[2] = 6;
    //Array 4 = 4294967295
    //rfile[1] = 32'h00000020;
    //rfile[2] = 12;
    
    end
    
    always @(*) begin
    rs_Reg = rfile[RS];
    rt_Reg = rfile[RT];
    
    if(RegWrite == 1)
        rfile[RD] = DataIN;

    end
endmodule
