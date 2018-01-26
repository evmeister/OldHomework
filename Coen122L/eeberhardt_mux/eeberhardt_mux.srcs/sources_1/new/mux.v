`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Evan Eberhardt 
// 
// Create Date: 04/18/2017 03:21:05 PM
// Design Name: eeberhardt_mux
// Module Name: mux
// Project Name: Lab 1
//////////////////////////////////////////////////////////////////////////////////


module mux(
    input Clock,
    input [31:0] a,
    input {31:0] b,
    input {31:0] c,
    input {31:0] d,
    input [1:0] s,
    output [31:0] o
    );
    reg o;
    //always @(a or b or c or d or s)
    always @(posedge clock)
    begin
        if (s == 2'b00) o = a;
        else if (s == 2'b01) o = b;
        else if (s == 2'b10) o = c;
        else o = d;
     end
endmodule
