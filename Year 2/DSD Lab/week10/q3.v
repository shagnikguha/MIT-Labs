module tff(t,q,reset,clk);
input t,reset,clk;
output reg q;
always @(negedge clk)
begin
if(reset)
q<=0;
else if(t)
q<=~q;
end
endmodule
module q3(q,clk,reset);
input clk,reset;
output [0:3]q;
tff stg1(1'b1,q[3],reset,clk);
tff stg2(1'b1,q[2],reset,q[3]);
tff stg3(1'b1,q[1],reset,q[2]);
tff stg4(1'b1,q[0],reset,q[1]);
endmodule
