module srff(S, R, Q, clk, reset, inp);
input S, R, clk, reset, inp;
output reg Q;
always @(posedge clk or posedge reset)
begin
if(reset)
     Q<=inp;
else
begin
     case({S,R})
        2'b00:Q<=Q;
        2'b01:Q<=1'b0;
        2'b10:Q<=1'b1;
        2'b11:Q<=1'bX;
     endcase
end
end
endmodule

module l10q2(A, clk, reset);
input clk, reset;
output [2:0]A;
srff st0((~A[1]&~A[0]),(A[2]&~A[1]),A[2],clk,reset,1'b0);
srff st1((~A[2]&~A[1]),((A[2]&~A[0])|(~A[2]&A[1]&A[0])), A[1], clk, reset, 1'b0);
srff st2(~A[0], ((~A[2]&A[0])|(A[1]&A[0])), A[0], clk, reset, 1'b1);
endmodule
     
