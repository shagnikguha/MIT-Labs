module Comparator_3b(a,b,gt,eq,lt);
input [2:0]a,b;
output gt, eq, lt;
wire i2, i1, i0;
wire t1, t2 ,t3;

assign i2 = ~(a[2]^b[2]);
assign i1 = ~(a[1]^b[1]);
assign i0 = ~(a[0]^b[0]);

assign eq = (i2& i1 & i0);

assign t1 = (a[2]&~b[2]);
assign t2 = (a[1]&~b[1]&i2);
assign t3 = (a[0]&~b[0]&i2&i1);

assign gt = (t1|t2|t3);

assign lt = ~(eq|gt);
endmodule
