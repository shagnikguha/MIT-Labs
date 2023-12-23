`timescale 1ns/1ns
`include "Mux4_1.v"

module Mux4_1_tb;
reg [0:3]w;
reg [1:0]s;
wire f;

Mux4_1 M1(w, s, f);
initial begin
	
	$dumpfile("Mux4_1_tb.vcd");
	$dumpvars(0, Mux4_1_tb);
	
	w = 4'b1101;
	s = 2'b00;
	#20;
	
	w = 4'b1101;
	s = 2'b01;
	#20; 

	w = 4'b1101;
	s = 2'b10;
	#20;
	
	w = 4'b1101;
	s = 2'b11;
	#20;	
	
	$display("Test Complete");
	$finish;
end
endmodule
