`timescale 1ns/1ns
`include "tFF.v"

module tFF_tb;
reg t, clk, reset;
wire q;
  
tFF tFFq(t, clk, reset, q);
initial begin
	$dumpfile("tFF_tb.vcd");
	$dumpvars(0, tFF_tb);
	clk = 0;
	forever #20 clk = ~clk;
end
initial begin
	t = 1; reset = 0; #10;
	t = 1; reset = 1; #20;
	t = 1; reset = 1; #10;
	t = 1; reset = 1; #10;
	t = 1; reset = 0; #20;
	t = 0; reset = 0; #10;
	$display("Test Complete");
	$finish;
end
endmodule
   
