`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Evan Eberhardt
// James Olwell
//
// Create Date: 05/22/2017 06:26:48 PM
// Design Name: CPU
// Module Name: control
// Project Name: Coen122 Projecy
//////////////////////////////////////////////////////////////////////////////////


module control(
    input Clock,
    input [3:0] opcode,
    output reg regwrt,
    output reg [1:0] toreg,
    output reg BrN,
    output reg BrZ,
    output reg J,
    output reg JM,
    output reg [2:0] ALUop,
    output reg mrd,
    output reg mwrt
    );
    
    initial begin
        regwrt = 0;
        toreg   = 0;
        BrN     = 0;
        BrZ     = 0;
        J       = 0;
        JM      = 0;
        ALUop   = 3;
        mrd     = 0;
        mwrt    = 0;
    end
    
    always @(*)
    begin
        case (opcode)
            4'b0000 : begin //NOP
                            regwrt  = 0;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 3;
                            mrd     = 0;
                            mwrt    = 0;
                      end
            4'b1111 : begin //LDPC
                            regwrt  = 1;
                            toreg   = 2;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 3;
                            mrd     = 0;
                            mwrt    = 0;
                      end
            4'b1110 : begin //LD
                            regwrt  = 1;
                            toreg   = 1;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 3;
                            mrd     = 1;
                            mwrt    = 0;
                      end
            4'b0011 : begin //ST
                            regwrt  = 0;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 3;
                            mrd     = 0;
                            mwrt    = 1;
                      end
            4'b0100 : begin //ADD
                            regwrt  = 1;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 4;
                            mrd     = 0;
                            mwrt    = 0;
                      end
            4'b0101 : begin //INC
                            regwrt  = 1;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 2;
                            mrd     = 0;
                            mwrt    = 0;
                      end
            4'b0110 : begin //NEG
                            regwrt  = 1;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 1;
                            mrd     = 0;
                            mwrt    = 0;
                      end
            4'b0111 : begin //SUB
                            regwrt  = 1;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 0;
                            mrd     = 0;
                            mwrt    = 0;
                      end
            4'b1000 : begin //J
                            regwrt  = 0;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 1;
                            JM      = 0;
                            ALUop   = 7;
                            mrd     = 0;
                            mwrt    = 0;
                      end
            4'b1001 : begin //BRZ
                            regwrt  = 0;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 1;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 7;
                            mrd     = 0;
                            mwrt    = 0;
                      end
            4'b1010 : begin //JM
                            regwrt  = 0;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 1;
                            ALUop   = 3;
                            mrd     = 1;
                            mwrt    = 0;
                      end
            4'b1011 : begin //BRN
                            regwrt  = 0;
                            toreg   = 0;
                            BrN     = 1;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 7;
                            mrd     = 0;
                            mwrt    = 0;
                      end   
            default : begin //NOP
                            regwrt  = 0;
                            toreg   = 0;
                            BrN     = 0;
                            BrZ     = 0;
                            J       = 0;
                            JM      = 0;
                            ALUop   = 3;
                            mrd     = 0;
                            mwrt    = 0;
                      end
        endcase
    end    
endmodule
