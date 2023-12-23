`timescale 1ns/1ns
`include "Comparator_3b.v"

module Comparator_3b_tb;
reg [2:0]a;
reg [2:0]b;
wire gt, eq, lt;

Comparator_3b c1(a,b,gt,eq,lt);
initial begin
	
	$dumpfile("Comparator_3b_tb.vcd");
	$dumpvars(0, Comparator_3b_tb);
	
	a = 3'b101;
	b = 3'b010;
	#20;
	
	a = 3'b000;
	b = 3'b010;
	#20;
	
	a = 3'b011;
	b = 3'b011;
	#20;
	
	$display("Test Complete");
	$finish;
end
endmodule
