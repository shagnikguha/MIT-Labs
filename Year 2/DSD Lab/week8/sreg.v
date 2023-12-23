module dffp(D, Clock, Q);
	input D, Clock;
	output reg Q;
	always @(posedge Clock)
		Q <= D;
endmodule

module sreg(Q, clk, A);
	input Q;
	input clk;
	output A;
	wire [5:1]I;
	dffp s1(Q , clk, I[5]);
	dffp s2(I[5], clk, I[4]);
	dffp s3(I[4], clk, I[3]);
	dffp s4(I[3], clk, I[2]);
	dffp s5(I[2], clk, I[1]);
	dffp s6(I[1], clk, A);
endmodule
