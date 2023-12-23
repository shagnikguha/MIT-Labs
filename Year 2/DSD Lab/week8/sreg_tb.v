`timescale 1ns/1ns
`include "sreg.v"

module sreg_tb;
reg Q, clk;
wire A;
  
sreg sr1(Q, clk, A);
initial begin
	$dumpfile("sreg_tb.vcd");
	$dumpvars(0, sreg_tb);
	clk = 0;
	forever #10 clk = ~clk;
end
initial begin
	Q = 0; #20;
	Q = 0; #20;
	Q = 0; #20;
	Q = 0; #20;
	Q = 0; #20;
	Q = 1; #20;
	Q = 0; #20;
	Q = 1; #20;
	Q = 0; #20;
	Q = 1; #20;
	Q = 0; #20;
	$display("Test Complete");
	$finish;
end
endmodule
   
