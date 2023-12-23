`timescale 1ns/1ns
`include "srFF.v"

module srFF_tb;
reg s,r,clk,reset;
wire q;

srFF srFFq(s,r,clk,reset,q);
initial begin
    $dumpfile("srFF_tb.vcd");
    $dumpvars(0,srFF_tb);
    clk = 1;
    forever #20 clk = ~clk;
end
initial begin
    s=0;r=0;reset=1;#10;
    s=0;r=0;reset=0;#20;
    s=1;r=0;reset=0;#20;
    s=0;r=1;reset=0;#20;
    s=1;r=1;reset=0;#20;
    s=0;r=0;reset=1;#20;
    s=0;r=0;reset=0;#10;
    $display("Test Complete");
    $finish;
end
endmodule
