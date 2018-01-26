`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/22/2017 06:42:33 PM
// Design Name: 
// Module Name: SourceTruth
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module SourceTruth(
    input clk,
    input brn,
    input n,
    input brz,
    input z,
    input j,
    input jm,
    output reg [1:0] out
    );
    
    always @(posedge clk)
    
    if(brn == brz == j == jm == 0)
        begin
            assign out = 0;
        end
    else if(brn == brz == j == 0 && jm == 1)
        begin
            assign out = 2;
        end
    else if((brn == n == 1 && brz == j == jm == 0) || (brn == j == jm == 0 && brz == z == 1) || (brn == brz == jm == 0 && j == 1))
        begin
            assign out = 1;
        end
    else
        begin
            assign out = 0;
        end
endmodule
