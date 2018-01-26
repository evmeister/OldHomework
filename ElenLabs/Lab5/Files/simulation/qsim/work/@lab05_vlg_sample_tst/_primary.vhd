library verilog;
use verilog.vl_types.all;
entity Lab05_vlg_sample_tst is
    port(
        High            : in     vl_logic;
        Low             : in     vl_logic;
        Switch          : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end Lab05_vlg_sample_tst;
