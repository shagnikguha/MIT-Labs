module tFF(t,q,clk,reset);
input clk,t,reset;
output reg q;
always @(posedge clk or posedge reset)begin
if(reset)q<=1'b0;
else begin
if(t==1'b0)q<=q;
else q<=~q;
end
end
endmodule
module p2(clk,x,reset,A,B);
input clk,x,reset;
output A,B;
wire[1:0]s;
assign s[1]=(B&~x)|(~A&B);
assign s[0]=(A&~x)|(~B&~x)|(~A&B&x);
tFF st0(s[1],A,clk,reset);
tFF st1(s[0],B,clk,reset);
endmodule
