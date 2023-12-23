`timescale 1ns/1ns
`include"q3.v"
module q3_tb;
reg clk,reset;
wire[0:3]q;
q3 out(q,clk,reset);
initial begin
clk=1;
forever#10 clk=~clk;
end 
initial begin
$dumpfile("q3_tb.vcd");
$dumpvars(0,q3_tb);
reset=1;#20;
reset=0;#350;
$display("Test completed");
$finish;
end
endmodule
