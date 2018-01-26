`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Evan Eberhardt
// James Olwell
// 
// Create Date: 06/05/2017 05:45:26 PM
// Module Name: CPU
// Project Name: Final Project
//////////////////////////////////////////////////////////////////////////////////
module PC_( 
    input Clock, 
    input [31:0] in,   
    output reg [31:0] out
    );
    
    //reg [31:0] out;
    
    initial begin
        out = 0;
    end
    
    always @(*) 
    begin 
        out = in; 
    end
endmodule 

module CPU(
    input Clock,
    
    output wire [31:0] Imem_to_IFIDBuffer, 
    output wire regwrt_to_Rfile,
    output wire [1:0] toreg_to_mux_1,
    output wire BrN_to_PCSource,
    output wire BrZ_to_PCSource,
    output wire J_to_PCSource,
    output wire JM_to_PCSource,
    output wire Z_to_PCSource,
    output wire N_to_PCSource,
    output wire [2:0] ALUop_to_ALU,
    output wire mrd_to_Dmem,
    output wire mwrt_to_Dmem,
    output wire [3:0] opcode_to_control,
    output wire [5:0] rd_to_IDEXBuffer,
    output wire [5:0] rs_to_Rfile,
    output wire [5:0] rt_to_Rfile,
    output wire [21:0] X_to_SignExtend,
    output wire [31:0] Adder_1_to_IDEXBuffer,
    output wire [31:0] RS_to_Dmem_ALU,
    output wire [31:0] RT_to_Dmem_ALU,
    output wire [31:0] out_to_EXWBBuffer,
    output wire Z_to_EXWBBuffer,
    output wire N_to_EXWBBuffer,
    output wire [31:0] sum_to_EXWBBuffer,
    output wire [5:0] rd_to_Rfile,
    output wire [31:0] mux_1_to_Rfile,
    output wire [31:0] mux_0_to_PC,
    output wire [31:0] PC,
    output wire [1:0] PCSource_to_mux_0   
    );
    //reg Clock;

    //First Stage-----
    //Wires from fourth stage
    wire [31:0] sum_to_mux;
    wire [31:0] out_to_mux;
    //wire [1:0] PCSource_to_mux_0;
    
    //Other Wires
    wire [31:0] Adder_0_to_mux_0;
    //wire [31:0] Imem_to_IFIDBuffer;
    
    //Modules
    //reg [31:0] PC;
    PC_ PC__(
        .Clock(Clock),
        .in(mux_0_to_PC),
        .out(PC)
     );
    
    mux mux_0(
        .Clock(Clock),
        .a(Adder_0_to_mux_0),
        .b(sum_to_mux),
        .c(out_to_mux),
        .d(out_to_mux), //unused
        .s(PCSource_to_mux_0),
        .o(mux_0_to_PC)
    );
    //reg one;
    //initial one = 1;
    Addone Adder_0(
        .Clock(Clock),
        .A(PC),
        .Out(Adder_0_to_mux_0)
    );
    
    Imem Imem_(
        .Clock(Clock),
        .PC_addr(PC),
        .Instruction(Imem_to_IFIDBuffer)
    );
    
    
    //IF/ID Buffer-----
    //Wires out of buffer
    //wire [3:0] opcode_to_control;
    //wire [5:0] rd_to_IDEXBuffer;
    //wire [5:0] rs_to_Rfile;
    //wire [5:0] rt_to_Rfile;
    //wire [21:0] X_to_SignExtend;
    wire [31:0] PC_to_Adder_1;
    
    IFIDBuffer IFIDBuffer_(
        .Clock(Clock),
        //Im
        .inst(Imem_to_IFIDBuffer),
        .PC_in(PC),
        //Out
        .opcode(opcode_to_control),
        .rd(rd_to_IDEXBuffer),
        .rs(rs_to_Rfile),
        .rt(rt_to_Rfile),
        .X(X_to_SignExtend),
        .PC(PC_to_Adder_1)
    );
    
    
   //Second Stage-----
   //Wires from fourth stage
   //wire regwrt_to_Rfile;
   //wire [31:0] mux_1_to_Rfile;
   //wire [5:0] rd_to_Rfile;
   
   //Wires out of control
   wire regwrt_to_IDEXBuffer;
   wire [1:0] toreg_to_IDEXBuffer;
   wire BrN_to_IDEXBuffer;
   wire BrZ_to_IDEXBuffer;
   wire J_to_IDEXBuffer;
   wire JM_to_IDEXBuffer;
   wire [2:0] ALUop_to_IDEXBuffer;
   wire mrd_to_IDEXBuffer;
   wire mwrt_to_IDEXBuffer;
   
   //Wires out of Rfile
   wire [31:0] RS_to_IDEXBuffer;
   wire [31:0] RT_to_IDEXBuffer;
   
   //Other wires
   wire [31:0] SignExtend_to_Adder_1;
   //wire [31:0] Adder_1_to_IDEXBuffer;
   
   //Modules
   control control_(
        .Clock(Clock),
        .opcode(opcode_to_control),
        .regwrt(regwrt_to_IDEXBuffer),
        .toreg(toreg_to_IDEXBuffer),
        .BrN(BrN_to_IDEXBuffer),
        .BrZ(BrZ_to_IDEXBuffer),
        .J(J_to_IDEXBuffer),
        .JM(JM_to_IDEXBuffer),
        .ALUop(ALUop_to_IDEXBuffer),
        .mrd(mrd_to_IDEXBuffer),
        .mwrt(mwrt_to_IDEXBuffer)
    );
    
    Rfile Rfile_(
        .Clock(Clock),
        .RegWrite(regwrt_to_Rfile),
        .RS(rs_to_Rfile),
        .RT(rt_to_Rfile),
        .RD(rd_to_Rfile),
        .DataIN(mux_1_to_Rfile),
        .rs_Reg(RS_to_IDEXBuffer),
        .rt_Reg(RT_to_IDEXBuffer)
    );
    
    SignExtend SignExtend_(
        .Clock(Clock),
        .In(X_to_SignExtend),
        .Out(SignExtend_to_Adder_1)
    );
    
    Adder Adder_1(
        .Clock(Clock),
        .A(SignExtend_to_Adder_1),
        .B(PC_to_Adder_1),
        .Out(Adder_1_to_IDEXBuffer)
    );
    
    
    //ID/EX Buffer-----
    //Wires out of buffer
    wire regwrt_to_EXWBBuffer;
    wire [1:0] toreg_to_EXWBBuffer;
    wire BrZ_to_EXWBBuffer;
    wire BrN_to_EXWBBuffer;
    wire J_to_EXWBBuffer;
    wire JM_to_EXWBBuffer;
    //wire [2:0] ALUop_to_ALU;
    //wire mrd_to_Dmem;
    //wire mwrt_to_Dmem;
    wire [5:0] rd_to_EXWBBuffer;
    //wire [31:0] RS_to_Dmem_ALU;
    //wire [31:0] RT_to_Dmem_ALU;
    wire [31:0] PC_to_EXWBBuffer;
    
    IDEXBuffer IDEXBuffer_(
         .Clock(Clock),
        //In    
        .regwrt_in(regwrt_to_IDEXBuffer),
        .toreg_in(toreg_to_IDEXBuffer),
        .brn_in(BrN_to_IDEXBuffer),
        .brz_in(BrZ_to_IDEXBuffer),
        .J_in(J_to_IDEXBuffer),
        .JM_in(JM_to_IDEXBuffer),
        .ALUop_in(ALUop_to_IDEXBuffer),
        .mrd_in(mrd_to_IDEXBuffer),
        .mwrt_in(mwrt_to_IDEXBuffer),
        .rd_in(rd_to_IDEXBuffer),
        .RS_in(RS_to_IDEXBuffer),
        .RT_in(RT_to_IDEXBuffer),
        .PCplusX(Adder_1_to_IDEXBuffer),
        //Out
        .regwrt(regwrt_to_EXWBBuffer),
        .toreg(toreg_to_EXWBBuffer),
        .brn(BrN_to_EXWBBuffer),
        .brz(BrZ_to_EXWBBuffer),
        .J(J_to_EXWBBuffer),
        .JM(JM_to_EXWBBuffer),
        .ALUop(ALUop_to_ALU),
        .mrd(mrd_to_Dmem),
        .mwrt(mwrt_to_Dmem),
        .rd(rd_to_EXWBBuffer),
        .RS(RS_to_Dmem_ALU),
        .RT(RT_to_Dmem_ALU),
        .PC(PC_to_EXWBBuffer)
    );
    
    
    //Third Stage-----
    //Wires out of ALU
    //wire Z_to_EXWBBuffer;
    //wire N_to_EXWBBuffer;
    //wire [31:0] sum_to_EXWBBuffer;
    //Wire out of Dmem
    //wire [31:0] out_to_EXWBBuffer;
    
    //Modules
    alu ALU_(
        .Clock(Clock),
        .opcode(ALUop_to_ALU),
        .a(RS_to_Dmem_ALU),
        .b(RT_to_Dmem_ALU),
        .out(sum_to_EXWBBuffer),
        .Z(Z_to_EXWBBuffer),
        .N(N_to_EXWBBuffer)
    );
    
    Dmem Dmem_(
        .Clock(Clock),
        .MemWrite(mwrt_to_Dmem),
        .MemRead(mrd_to_Dmem),
        .DataAddr(RS_to_Dmem_ALU),
        .DataIN(RT_to_Dmem_ALU),
        .DataRead(out_to_EXWBBuffer)
    );
    
    
    //EX/WB Buffer-----
    //Wires out of buffer
    //wire regwrt_to_Rfile goes to second stage
    //wire [1:0] toreg_to_mux_1;
    //wire BrZ_to_PCSource;
    //wire BrN_to_PCSource;
    //wire J_to_PCSource;
    //wire JM_to_PCSource;
    //wire N_to_PCSource;
    //wire Z_to_PCSource;
    //wire [31:0] sum_to_mux goes to first stage 
    //wire [31:0] out_to_muz goes to first stage
    //wire [5:0] rd_to_Rfile goes to second stage
    wire [31:0] PC_to_mux_1;
    
    EXWBBuffer EXWBBuffer_(
        .Clock(Clock),
        //In
        .regwrt_in(regwrt_to_EXWBBuffer),
        .toreg_in(toreg_to_EXWBBuffer),
        .brz_in(BrZ_to_EXWBBuffer),
        .brn_in(BrN_to_EXWBBuffer),
        .J_in(J_to_EXWBBuffer),
        .JM_in(JM_to_EXWBBuffer),
        .N_in(N_to_EXWBBuffer),
        .Z_in(Z_to_EXWBBuffer),
        .sum_in(sum_to_EXWBBuffer),
        .out_in(out_to_EXWBBuffer),
        .rd_in(rd_to_EXWBBuffer),
        .PC_in(PC_to_EXWBBuffer),
        //Out
        .regwrt(regwrt_to_Rfile),
        .toreg(toreg_to_mux_1),
        .brz(BrZ_to_PCSource),
        .brn(BrN_to_PCSource),
        .J(J_to_PCSource),
        .JM(JM_to_PCSource),
        .N(N_to_PCSource),
        .Z(Z_to_PCSource),
        .sum(sum_to_mux),
        .out(out_to_mux),
        .rd(rd_to_Rfile),
        .PC(PC_to_mux_1)
    );
    
    
    //Fourth Stage
    //Wires
    //wire mux_1_to_Rfile goes to stage 2
    //wire PCSource_to_mux_0 goes to stage 1
    
    //Modules
    PCSource PCSource_(
        .clk(Clock),
        .brn(BrN_to_PCSource),
        .n(N_to_PCSource),
        .brz(BrZ_to_PCSource),
        .z(Z_to_PCSource),
        .j(J_to_PCSource),
        .jm(JM_to_PCSource),
        .out(PCSource_to_mux_0)
    );
    
    mux mux_1(
        .Clock(Clock),
        .a(sum_to_mux),
        .b(out_to_mux),
        .c(PC_to_mux_1),
        .d(PC_to_mux_1),
        .s(toreg_to_mux_1),
        .o(mux_1_to_Rfile)
    );
    
    
    /*
        initial begin
             Clock = 0;
             forever #5 Clock = ~Clock;
             end
             //*/
    
endmodule
//Wires out of fourth stage
//sum_to_mux
//out_to_mux
//PCSource_to_mux_0
//regwrt_to_Rfile
//mux_1_to_Rfile
//rd_to_Rfile