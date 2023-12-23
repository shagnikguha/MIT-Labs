`timescale 1ns/1ns
`include "btogray.v"

module btogray_tb;
reg [3:0]b;
wire [3:0]g;

btogray b1(b, g);
initial begin
	
	$dumpfile("btogray_tb.vcd");
	$dumpvars(0, btogray_tb);
	
	b = 4'b0010;
	#20;
	
	b = 4'b0100;
	#20; 
	
	b = 4'b1100;
	#20; 
	
	b = 4'b1000;
	#20; 
	
	$display("Test Complete");
	$finish;
end
endmodule
