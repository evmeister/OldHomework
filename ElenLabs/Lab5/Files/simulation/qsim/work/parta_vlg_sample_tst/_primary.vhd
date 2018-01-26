library verilog;
use verilog.vl_types.all;
entity parta_vlg_sample_tst is
    port(
        SW0             : in     vl_logic;
        SW1             : in     vl_logic;
        SW2             : in     vl_logic;
        SW3             : in     vl_logic;
        SW4             : in     vl_logic;
        SW5             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end parta_vlg_sample_tst;
