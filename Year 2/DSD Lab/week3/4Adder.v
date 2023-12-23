module FullAdder(Ci, Xi, Yi, Si, Cout);
input Ci, Xi, Yi;
output Cout, Si;
assign Si = Ci^Xi^Yi;
assign Cout = (Xi&Yi)|(Ci&Yi)|(Ci&Xi);
endmodule

module 4adder(x, y, Cin, Cout, S);
input [3:0]x,y;
input Cin;
output Cout;
output [3:0]S;
wire [3:1]C;

FullAdder stage0(Cin, x[0], y[0], S[0], C[1]);
FullAdder stage1(C[1], X[1], Y[1],S[1],C[2]);
FullAdder stage2(C[2], X[2], Y[2], S[2], C[3]);
FullAdder stage3(C[3], X[3], Y[3], S[3]);
endmodule









