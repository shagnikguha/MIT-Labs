module Q1_b(A, B, C, D, f);
input A, B, C, D;
output f;
assign f = (B&~C)|(C&~D);
endmodule
