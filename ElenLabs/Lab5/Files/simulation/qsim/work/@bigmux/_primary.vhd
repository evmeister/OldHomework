library verilog;
use verilog.vl_types.all;
entity Bigmux is
    port(
        \OUT\           : out    vl_logic;
        IN3             : in     vl_logic;
        IN2             : in     vl_logic;
        S0              : in     vl_logic;
        IN1             : in     vl_logic;
        IN0             : in     vl_logic;
        S1              : in     vl_logic
    );
end Bigmux;
