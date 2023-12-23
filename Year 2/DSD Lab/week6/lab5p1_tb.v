`timescale 1ns/1ns
`include "lab5p1.v"

module lab5p1_tb;
reg [0:3]W;
wire f;

lab5p1 uut(W, f);
initial begin
	
	$dumpfile("lab5p1.vcd");
	$dumpvars(0, lab5p1_tb);
	
	W = 4'b0000;
	#20;
	
	W = 4'b0001;
	#20;
	
	W = 4'b0010;
	#20;
	
	W = 4'b0011;
	#20;
	
	W = 4'b0100;
	#20;
	
	W = 4'b0101;
	#20;
	
	W = 4'b0110;
	#20;
	
	W = 4'b0111;
	#20;
	
	W = 4'b1000;
	#20;
	
	W = 4'b1001;
	#20;
	
	W = 4'b1010;
	#20;
	
	W = 4'b1011;
	#20;
	
	W = 4'b1100;
	#20;
	
	W = 4'b1101;
	#20;
	
	W = 4'b1110;
	#20;
	
	W = 4'b1111;
	#20;
	
	$display("Test Complete");
	$finish;
end
endmodule
