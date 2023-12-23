`timescale 1ns/1ns
`include "example1.v"

module example1_tb;
reg x1, x2, x3;
wire f;

example1 e1(x1, x2, x3, f);
initial begin
	
	$dumpfile("example1_tb.vcd");
	$dumpvars(0, example1_tb);
	
	x1 = 0;
	x2 = 0;
	x3 = 0;
	#20;
	
	x1 = 0;
	x2 = 1;
	x3 = 0;
	#20;
	
	x1 = 1;
	x2 = 0;
	x3 = 0;
	#20;
	
	x1 = 1;
	x2 = 1;
	x3 = 0;
	#20;
	
	x1 = 0;
	x2 = 0;
	x3 = 1;
	#20;
	
	x1 = 1;
	x2 = 0;
	x3 = 1;
	#20;
	
	x1 = 0;
	x2 = 1;
	x3 = 1;
	#20;
	
	x1 = 1;
	x2 = 1;
	x3 = 1;
	#20;
	
	$display("Test Complete");
end
endmodule
