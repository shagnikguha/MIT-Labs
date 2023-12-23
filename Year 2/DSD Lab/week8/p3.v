module dFF(Q,D,clk);
	input D;
	input clk;
	output reg Q;
	always @(posedge clk)
	begin 
		Q<=D;
	end
endmodule

module mux4to1(S,W,F);
	input [1:0]S;
	input [3:0]W;
	output reg F;
	always @(S,W)
	begin
		case(S)
		2'b00: F = W[0];
		2'b01: F = W[1];
		2'b10: F = W[2];
		2'b11: F = W[3];
		endcase
	end
endmodule

module p3(I, S, clk, inp, A);
	input [3:0]I;
	input [1:0]S;
	input clk, inp;
	output [3:0]A;

	wire [3:0]M3, M2, M1, M0, D;
	assign M3 = {A[3], A[3], I[3], A[2]};
	assign M2 = {A[2], A[2], I[2], A[1]};
	assign M1 = {A[1], A[1], I[1], A[0]};
	assign M0 = {A[0], A[0], I[0], inp};
	mux4to1 st0(S, M3, D[3]);
	mux4to1 st1(S, M2, D[2]);
	mux4to1 st2(S, M1, D[1]);
	mux4to1 st3(S, M0, D[0]);
	dFF st4(A[3], D[3], clk);
	dFF st5(A[2], D[2], clk);
	dFF st6(A[1], D[1], clk);
	dFF st7(A[0], D[0], clk);
endmodule

	
