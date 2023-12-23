module jkff(J, K, Q, clk, reset);
input J,K,clk,reset;
output reg Q;
always @(posedge clk or posedge reset)
begin
if(reset)
   Q<=1'b0;
else
begin
   case({J,K})
     2'b00: Q<=Q;
     2'b01: Q<=1'b0;
     2'b10: Q<=1'b1;
     2'b11: Q<=~Q;
   endcase
end
end
endmodule

module l10q1(A, clk, reset);
input clk, reset;
output [2:0]A;
jkff stg0(A[1],(A[1]&A[0]),A[2],clk,reset);
jkff stg1(A[0],(A[0]|~A[2]),A[1],clk,reset);
jkff stg2((A[2]|~A[1]),1'b1,A[0],clk,reset);
endmodule

     
