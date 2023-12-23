`timescale 1ns/1ns
`include "q1.v"
module q1_tb;
reg reset,clk;
wire [3:0]q;
q1 out(reset,clk,q);
initial begin
clk=1;
forever#10 clk=~clk;
end 
initial begin
$dumpfile("q1_tb.vcd");
$dumpvars(0,q1_tb);
reset=1;#20;
reset=0;#80;
$display("test completed");
$finish;
end 
endmodule

