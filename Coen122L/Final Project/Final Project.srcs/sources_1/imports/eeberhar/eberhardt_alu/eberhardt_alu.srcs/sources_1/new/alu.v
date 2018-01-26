`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Evan Eberhardt
// 
// Create Date: 04/25/2017 02:36:55 PM
// Design Name: eberhardt_alu
// Module Name: alu
// Project Name: Lab 2
//////////////////////////////////////////////////////////////////////////////////


module alu(
    input Clock,
    input [2:0] opcode,
    input [31:0] a,
    input [31:0] b,
    output reg [31:0] out,
    output reg Z,
    output reg N
    );
    initial begin out = 0; Z = 0; N = 0; end
    always @(*)
    begin
        case (opcode)
            3'b100 : begin out = a + b; end //add
            3'b010 : begin out = a + 1; end //increment
            3'b001 : begin out = -a; end //negate
            3'b000 : begin out = a + (-b); end //subtract
            3'b011 : begin end //nop
            3'b111 : begin out = a; end //pass
            default: out = 32'bXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX; //default
        endcase
        if( out == 0 )
            Z = 1;
        else if(opcode == 7);
        else
            Z = 0;
        if( out[31] == 1 ) 
            N = 1;
        else if(opcode == 7);
        else N = 0;
    end          
endmodule
