`timescale 1ns/1ns
`include "dFF.v"

module dFF_tb;
reg d, clk, reset;
wire q;
  
dFF dFFq(d, clk, reset, q);
initial begin
	$dumpfile("dFF_tb.vcd");
	$dumpvars(0, dFF_tb);
	clk = 0;
	forever #20 clk = ~clk;
end
initial begin
	d = 1; reset = 1; #10;
	d = 1; reset = 0; #20;
	d = 1; reset = 1; #10;
	d = 0; reset = 1; #10;
	d = 1; reset = 0; #20;
	d = 0; reset = 0; #10;
	$display("Test Complete");
	$finish;
end
endmodule
   
