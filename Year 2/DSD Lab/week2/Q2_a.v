module Q2_a(A, B, C, D, f);
input A, B, C, D;
output f;
assign f = (C|D)&(C|B)&(~A|~B|~C|~D);
endmodule 
