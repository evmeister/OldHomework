`timescale 1ns / 1ps


module Adder(
    input [31:0] A,
    input [31:0] B,
    output [31:0] Out
    );
    
    assign Out = A+B;
    
endmodule

module SignExtend(
    input [21:0] In,
    output [31:0] Out
    );
    
    assign Out = { {10{In[21]}}, In};
    
endmodule