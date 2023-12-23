`timescale 1ns/1ns
`include "Decoder2_4.v"

module Decoder2_4_tb;
reg [1:0]w;
reg e;
wire [0:3]y;

Decoder2_4 d1(w, e, y);
initial begin
	
	$dumpfile("Decoder2_4_tb.vcd");
	$dumpvars(0, Decoder2_4_tb);
	
	e = 1;
	w = 2'b00;
	#20;
	
	e = 1;
	w = 2'b01;
	#20;
	
	e = 1;
	w = 2'b10;
	#20;
	
	e = 1;
	w = 2'b11;
	#20;
	
	e = 0;
	w = 2'b11;
	#20;
	
	$display("Test Complete");
	$finish;
end
endmodule
