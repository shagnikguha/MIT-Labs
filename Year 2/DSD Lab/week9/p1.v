module dff(d,q,clk,reset);
input clk,d,reset;
output reg q;
always @ (posedge clk or posedge reset)begin
if(reset)q<=1'b0;
else q<=d;
end 
endmodule

module p1(clk,x,y,reset,lo);
input clk,x,reset;
output y;
output [2:0]lo;
wire [2:0]li,s;
assign s[2]=(~lo[0]&~x&lo[1])|(~x&lo[2]);
assign s[1]=(~lo[2]&~x&~lo[1]&~lo[0])|(x&lo[0])|(~x&lo[0]);
assign s[0]=(~lo[2]&~lo[1]&~lo[0])|(lo[1]&lo[0]);
dff st0(s[2],lo[2],clk,reset);
dff st1(s[1],lo[1],clk,reset);
dff st2(s[0],lo[0],clk,reset);
assign y=(lo[2]&x)|(lo[1]&~x)|(lo[1]&lo[0]);
assign lo=li;
endmodule
