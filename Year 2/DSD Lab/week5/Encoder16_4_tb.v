`timescale 1ns/1ns
`include "Encoder16_4.v"

module Encoder16_4_tb;
reg [15:0]w;
wire z;
wire [3:0]y;

Encoder16_4 e2(w, y, z);
initial begin
	
	$dumpfile("Encoder16_4_tb.vcd");
	$dumpvars(0, Encoder16_4_tb);

	w = 16'b0000000000000011;
	#20;
	
	w = 16'b1010000000000000;
	#20;
	
	w = 16'b0000000000000100;
	#20;
	
	w = 16'b0010000000000000;
	#20;
	
	w = 16'b0000000000000000;
	#20;
	
	$display("Test Complete");
	$finish;
end
endmodule
