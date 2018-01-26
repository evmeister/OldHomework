library verilog;
use verilog.vl_types.all;
entity Bigmux_vlg_sample_tst is
    port(
        IN0             : in     vl_logic;
        IN1             : in     vl_logic;
        IN2             : in     vl_logic;
        IN3             : in     vl_logic;
        S0              : in     vl_logic;
        S1              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end Bigmux_vlg_sample_tst;
