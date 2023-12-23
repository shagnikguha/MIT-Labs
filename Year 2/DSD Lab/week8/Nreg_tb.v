`timescale 1ns/1ns
`include "Nreg.v"

module Nreg_tb;
parameter n = 8;
reg [n-1:0]I;
reg clk;
wire [n-1:0]Q;
  
Nreg Nr1(I, clk, Q);
initial begin
	$dumpfile("Nreg_tb.vcd");
	$dumpvars(0, Nreg_tb);
	clk = 0;
	forever #10 clk = ~clk;
end
initial begin
	I = 8'b10101010;
	#20;
	I = 8'b01010101;
	#20;
	I = 8'b11101010;
	#20;
	I = 8'b01011111;
	#20;
	I = 8'b00000000;
	#20;
	I = 8'b01111100;
	#20;
	I = 8'b10000000;
	#20;
	I = 8'b00010001;
	#20;
	$display("Test Complete");
	$finish;
end
endmodule
   
