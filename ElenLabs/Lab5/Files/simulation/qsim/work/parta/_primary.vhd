library verilog;
use verilog.vl_types.all;
entity parta is
    port(
        LED0            : out    vl_logic;
        SW0             : in     vl_logic;
        SW1             : in     vl_logic;
        SW2             : in     vl_logic;
        SW3             : in     vl_logic;
        SW4             : in     vl_logic;
        SW5             : in     vl_logic
    );
end parta;
