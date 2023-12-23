module Mux4_1(w,s,f);
input [0:3]w;
input [1:0]s;
output reg f;

always @(w or s)
begin 
if(s==2'b00)
	f=w[0];
else if(s==2'b01)
	f = w[1];
     else if(s==2'b10)
     		f = w[2];
     	  else if(s==2'b11)
     	  	    f = w[3];
end
endmodule
