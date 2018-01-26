`timescale 1ns / 1ps


module Adder(
    input Clock,
    input [31:0] A,
    input [31:0] B,
    output reg [31:0] Out
    );
    initial begin Out = A + B; end
    always @(*) begin
        Out = A+B;
    end    
endmodule

module Addone(
    input Clock,
    input [31:0] A,
    output reg [31:0] Out
    );
    initial begin Out = A; end
    always @(posedge Clock) begin
        Out = A + 1;
    end
endmodule

module SignExtend(
    input Clock,
    input [21:0] In,
    output reg [31:0] Out
    );
    initial begin Out = 0; end
    always @(*) begin
        Out = { {10{In[21]}}, In};
    end    
endmodule