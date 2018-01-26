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
    initial begin DataRead = 0;
    //DEMO
    //$readmemh("C:\Users\eeberhar\Coen122L\Final Project\DemoNumbers.txt", dmem);
    
    dmem[11]= 32;

    dmem[32] = 32'h12345678;
    dmem[33] = 32'h87654321;
    dmem[34] = 32'h00000001;
    dmem[35] = 32'h00000010;
    dmem[36] = 32'h00000100;
    dmem[37] = 32'h00001000;
    dmem[38] = 32'h00010000;
    dmem[39] = 32'h00100000;
    dmem[40] = 32'h01000000;
    dmem[41] = 32'h10000000;
    dmem[42] = 32'h22222222;
    dmem[43] = 32'h33333333;

    dmem[64] = 32'h01010101;
    dmem[65] = 32'h10101010;
    dmem[66] = 32'h11111111;
    dmem[67] = 32'h0DDDDDDE;
    dmem[68] = 32'h03333333;
    dmem[69] = 32'h22222222;

    dmem[128] = 32'h00001111;
    dmem[129] = 32'h00002222;
    dmem[130] = 32'h00003333;
    dmem[131] = 32'h00004444;
    dmem[132] = 32'h11110000;
    dmem[133] = 32'h22220000;
    dmem[134] = 32'h33330000;
    dmem[135] = 32'h44440000;
    dmem[136] = 32'h11111111;
    dmem[137] = 32'h22222222;

    dmem[256] = 32'h0000000F;
    dmem[257] = 32'h000000F0;
    dmem[258] = 32'h00000F00;
    dmem[259] = 32'h0000F000;
    dmem[260] = 32'h000F0000;
    dmem[261] = 32'h00F00000;
    dmem[262] = 32'h0F000000;
    dmem[263] = 32'h60000001;
    //00000000;
    
    end
    
    always @(*) begin
    if(MemWrite == 1)
        dmem[DataAddr] = DataIN;
    else if(MemRead == 1)
        DataRead = dmem[DataAddr];
        
    end
endmodule
