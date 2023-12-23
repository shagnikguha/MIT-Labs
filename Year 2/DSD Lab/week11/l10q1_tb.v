`timescale 1ns/1ns
`include "l10q1.v"
module l10q1_tb;
reg clk, reset;
wire [2:0]A;

l10q1 uut(A, clk, reset);
initial
begin
clk=0;
forever begin
 #10  clk=~clk;
end
end
initial begin
    $dumpfile("l10q1_tb.vcd");
    $dumpvars(0,l10q1_tb);

    reset = 1; #20;
    reset = 0; #100;
    $display("Test complete");
    $finish;
end
endmodule
