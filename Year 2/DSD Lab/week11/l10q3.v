module tff(T, Q, clk, reset);
input T, clk, reset;
output reg Q;
always @(posedge clk or posedge reset)
begin
if(reset)
   Q<=1'b0;
else
begin
   case(T)
      1'b0:Q<=Q;
      1'b1:Q<=~Q;
   endcase
end
end
endmodule
module l10q3(A, clk, reset);
input clk ,reset;
output [2:0]A;
tff st0((A[2]^A[1]), A[2], clk, reset);
tff st1((A[1]^A[0]), A[1], clk, reset);
tff st2(~(A[2]^A[0]), A[0], clk, reset);
endmodule

