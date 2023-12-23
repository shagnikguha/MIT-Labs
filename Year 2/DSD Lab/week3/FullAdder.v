module FullAdder(Ci, Xi, Yi, Cout, Si);
input Ci, Xi, Yi;
output Cout, Si;
assign Si = Ci^Xi^Yi;
assign Cout = (Xi&Yi)|(Ci&Yi)|(Ci&Xi);
endmodule
