`timescale 1ns/1ns
`include"q2.v"
module q2_tb;
reg reset,clk;
wire[4:0]q;
q2 out(reset,clk,q);
initial begin 
clk=1;
forever#10 clk=~clk;
end
initial begin
$dumpfile("q2_tb.vcd");
$dumpvars(0,q2_tb);
reset=1;#20;
reset=0;#80;
$display("Test completed");
$finish;
end
endmodule
