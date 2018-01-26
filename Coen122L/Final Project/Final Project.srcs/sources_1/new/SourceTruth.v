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


module PCSource(
    input clk,
    
    input brn,
    input j,
    input brz,
    input jm,
    
    input n,
    input z,
    
    output reg [1:0] out
    );
    
    initial begin out = 0; end
    
    always @(*) 
    
    if(brn == 0 && brz == 0 && j == 0 && jm == 0)
        begin
            out = 0;
        end
    else if(brn == 0 && brz == 0 && j == 0 && jm == 1)
        begin
            out = 2;
        end
    else if((brn == 1 && n == 1 && brz == 0 && j == 0 && jm == 0)) 
        begin
            out = 1;
        end
    else if(brn == 0 && j == 0 && jm == 0 && brz == 1 && z == 1)
        begin
            out = 1;
        end 
    else if(brn == 0 && brz == 0 && jm == 0 && j == 1)
        begin
            out = 1;
        end
    else
        begin
            out = 0;
        end
        
endmodule
