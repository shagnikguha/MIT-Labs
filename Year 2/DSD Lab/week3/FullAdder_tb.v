`timescale 1ns/1ns
`include "FullAdder.v"

module FullAdder_tb;
reg Ci, Xi, Yi;
wire Cout, Si;

FullAdder F1(Ci, Xi, Yi, Cout, Si);
initial begin
	
	$dumpfile("FullAdder_tb.vcd");
	$dumpvars(0, FullAdder_tb);
	
	Ci = 0;
	Xi = 0;
	Yi = 0;
	#20;
	
	Ci = 0;
	Xi = 0;
	Yi = 1;
	#20;
	
	Ci = 0;
	Xi = 1;
	Yi = 0;
	#20;
	
	Ci = 0;
	Xi = 1;
	Yi = 1;
	#20;
	
	Ci = 1;
	Xi = 0;
	Yi = 0;
	#20;
	
	Ci = 1;
	Xi = 0;
	Yi = 1;
	#20;
	
	Ci = 1;
	Xi = 1;
	Yi = 0;
	#20;
	
	Ci = 1;
	Xi = 1;
	Yi = 1;
	#20;
	
	$display("Test Complete");
end
endmodule
