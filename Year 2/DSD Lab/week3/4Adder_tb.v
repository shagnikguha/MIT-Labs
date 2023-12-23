`timescale 1ns/1ns
`include "4Adder.v"

module 4Adder_tb;
reg Cin, x, y;
wire Cout, S;

4Adder f1(A, B, C, D, f);
initial begin
	
	$dumpfile("4Adder_tb.vcd");
	$dumpvars(0, 4Adder_tb);
	
	
