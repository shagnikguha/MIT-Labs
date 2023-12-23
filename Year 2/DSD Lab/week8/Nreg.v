module Nreg(I, clk, Q);
	parameter n = 8;
	input [n-1:0]I;
	input clk;
	output reg [n-1:0]Q;
	
	always @(posedge clk)
		Q<=I;
endmodule
	

