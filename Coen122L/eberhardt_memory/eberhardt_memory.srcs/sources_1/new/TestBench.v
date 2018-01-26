`timescale 1ns / 1ps

//Evan Eberhardt
//Memory Testbench

module memory_testbench;
    reg Clock;

    //Imem
    //inputs
    reg [31:0] PC_addr;
    //outputs
    wire [31:0] Instruction;
    
    //Rfile
    //inputs
    reg RegWrite;
    reg [5:0] RS;
    reg [5:0] RT;
    reg [5:0] RD;
    reg [31:0] DataIN_R;
    //outputs
    wire [31:0] rs_Reg;
    wire [31:0] rt_Reg;
    
    //Dmem
    //inputs
    reg MemWrite;
    reg MemRead;
    reg [31:0] DataAddr;
    reg [31:0] DataIN_D;
    //outputs
    wire [31:0] DataRead;
    
    //Modules
    Imem imem1(
        .Clock(Clock),
        //in
        .PC_addr(PC_addr),
        //out
        .Instruction(Instruction)
    );
    
    Rfile rfile1(
        .Clock(Clock),
        //in
        .RegWrite(RegWrite),
        .RS(RS),
        .RT(RT),
        .RD(RD),
        .DataIN(DataIN_R),
        //out
        .rs_Reg(rs_Reg),
        .rt_Reg(rt_Reg)
    );
    
    Dmem dmem1(
        .Clock(Clock),
        //in
        .MemWrite(MemWrite),
        .MemRead(MemRead),
        .DataAddr(DataAddr),
        .DataIN(DataIN_D),
        //out
        .DataRead(DataRead)
    );
    
    initial begin
        //Clock
        Clock = 0;
        forever #5 Clock = ~Clock;
    end
        
    initial begin
        /////////////
        //Testing
        //-------
        //Imem:
        //1)
        //Force a certain address of the imem block to a certain value.
        //Given that address as input PC_addr, the output Instruction should be the set value.
        //The value imem[200] is hardcoded to be the value 1028
        PC_addr = 200;
        #10;
        
        //Rfile:
        //1)
        //RegWrite = 1
        //For a given address and data as inputs RD and DataIN_R respectively, the chosen address RD in the rfile block should hold the value of DataIN_R.
        //Do this twice in preperation for the next test, which will verify this result as well.
        RegWrite = 1;
        RD = 10;
        DataIN_R = 256;
        #10;
        
        RegWrite = 1;
        RD = 20;
        DataIN_R = 512;
        #10;
        
        //2)
        //RegWrit = 0 
        //Two addresses of the rfile block hold certain values, as set by the previous test.
        //For each, given their respective addresses as inputs RS and RT, the corresponding outputs rs_Reg an rt_Reg should be the set values.
        //Expect rs_Reg to be 256 and rt_Reg to be 512
        RegWrite = 0;
        RS = 10;
        RT = 20;
        #10;
                
        //Dmem:
        //1)
        //MemRead = 0
        //MemWrite = 1
        //For a given address and data as inputs DataAddr and DataIN_D respectively, the chosen address DataAddr in the dmem block should hold the value of DataIN_D.
        //Do this once in preperation for the next test, which will verify this result as well.
        MemRead = 0;
        MemWrite = 1;
        DataAddr = 1028;
        DataIN_D = 2056;
        #10;
        
        //MemRead = 1
        //MemWrite = 0
        //An address in the dmem block holds a certain value, as set by the previous test.
        //Given that address as input in DataAddr, the output DataRead should be the set value.
        //Expect DataRead to be 2056
        MemRead = 1;
        MemWrite = 0;
        DataAddr = 1028;
        #10;
               
        //end testing
        /////////////
    end
endmodule
    
        
