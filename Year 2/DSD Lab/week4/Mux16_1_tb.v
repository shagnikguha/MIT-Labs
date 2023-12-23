`timescale 1ns/1ns
`include "Mux16_1.v"

module Mux16_1_tb;
reg [0:15]w;
reg [3:0]s;
wire f;

Mux16_1 M2(w, s, f);
initial begin
	
	$dumpfile("Mux16_1_tb.vcd");
	$dumpvars(0, Mux16_1_tb);
	
	w = 16'b0000000000000001;
	s = 4'b0000;
	#20;
	
	w = 16'b0000000000000001;
	s = 4'b1111;
	#20;
	
	w = 16'b0000000000000100;
	s = 4'b0010;
	#20;
	
	w = 16'b0010000000000000;
	s = 4'b1101;
	#20;	
	
	w = 16'b0010000000000000;
	s = 4'b0010;
	#20;
	
	w = 16'b0000000000000100;
	s = 4'b1101;
	#20;
	
	w = 16'b1000000000000000;
	s = 4'b0000;
	#20;
	
	w = 16'b0000010000000000;
	s = 4'b0101;
	#20;
	
	$display("Test Complete");
	$finish;
end
endmodule
