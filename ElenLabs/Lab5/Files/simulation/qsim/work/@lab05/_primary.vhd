library verilog;
use verilog.vl_types.all;
entity Lab05 is
    port(
        \Out\           : out    vl_logic;
        Low             : in     vl_logic;
        Switch          : in     vl_logic;
        High            : in     vl_logic
    );
end Lab05;
