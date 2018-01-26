`timescale 1ns / 1ps

//Evan Eberhardt
//ALU testbench

/*
module alu_testbench(
    input [3:0] opcode,
    input [31:0] a,
    input [31:0] b,
    output reg [31:0] operator,
    output reg Z,
    output reg N,
    wire [31:0] out,
    wire zero,
    wire neg
    );
*/
    
module alu_testbench;
    reg [3:0] opcode;
    reg [31:0] a;
    reg [31:0] b;
    
    wire[31:0] out;
    wire Z;
    wire N;

    alu m1(
        .opcode(opcode),
        .a(a),
        .b(b),
        .out(out),
        .Z(Z),
        .N(N)
    );
    
    initial
    begin
    
    // a + b
    a = 5;
    b = 10;
    opcode = 4'b0000;
    #1000;
    
    // out = b + 1  increment
    a = 0;
    b = 9;
    opcode = 4'b0001;
    #1000;
    
    // out = -a  2's Compliment
    a = -15;
    b = 0;
    opcode = 4'b0010;
    #1000;
        
    // a - b,  Z = 1
    a = 5;
    b = 5;
    opcode = 4'b0011;
    #1000;
    
    // a - b,  N = 1
    a = 15;
    b = 10;
    opcode = 4'b0011;
    #1000;
        
    // out = a  pass
    a = 20;
    b = 0;
    opcode = 4'b0100;
    #1000;
    
    end
endmodule 