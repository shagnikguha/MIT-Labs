`timescale 1ns/1ns
`include "jkFF.v"

module jkFF_tb;
reg j,k,clk,reset;
wire q;

jkFF jkFFq(j,k,clk,reset,q);
initial begin
    $dumpfile("jkFF_tb.vcd");
    $dumpvars(0,jkFF_tb);
    clk = 1;
    forever #20 clk = ~clk;
end
initial begin
    j=0;k=0;reset=1;#10;
    j=0;k=0;reset=0;#20;
    j=1;k=0;reset=0;#20;
    j=0;k=1;reset=0;#20;
    j=1;k=1;reset=0;#20;
    j=0;k=0;reset=1;#20;
    j=0;k=0;reset=0;#10;
    $display("Test Complete");
    $finish;
end
endmodule
