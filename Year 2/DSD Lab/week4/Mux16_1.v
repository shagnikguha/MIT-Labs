module Mux8_1(w,s,f);
input [0:7]w;
input [2:0]s;
output reg f;
always @(w or s)
case(s)
3'b000: f = w[0];
3'b001: f = w[1];
3'b010: f = w[2];
3'b011: f = w[3];
3'b100: f = w[4];
3'b101: f = w[5];
3'b110: f = w[6];
3'b111: f = w[7];
endcase
endmodule

module Mux2_1(w,s,f);
input [0:1]w;
input s;
output reg f;
always @(w or s)
case(s)
0: f = w[0];
1: f = w[1];
endcase
endmodule

module Mux16_1(w,s,f);
input [0:15]w;
input [3:0]s;
output f;
wire [0:1]m;
Mux8_1 mux1(w[0:7], s[2:0], m[0]);
Mux8_1 mux2(w[8:15], s[2:0], m[1]);
Mux2_1 mux3(m[0:1], s[3], f);
endmodule

