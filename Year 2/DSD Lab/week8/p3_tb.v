`timescale 1ns/1ns
`include "p3.v"

module p3_tb;
reg [3:0]I;
reg [1:0]S;
reg clk, inp;
wire [3:0]A;
  
p3 out(I, S, clk, inp, A);
initial begin
	$dumpfile("p3_tb.vcd");
	$dumpvars(0, p3_tb);
	clk = 0;
	forever #10 clk = ~clk;
end
initial begin
	I = 4'b0001;
	S = 2'b01;
	inp = 1;
	#20;
	I = 4'b0001;
	S = 2'b00;
	inp = 1;
	#20;
	I = 4'b1111;
	S = 2'b00;
	inp = 1;
	#20;
	$display("Test Complete");
	$finish;
end
endmodule
