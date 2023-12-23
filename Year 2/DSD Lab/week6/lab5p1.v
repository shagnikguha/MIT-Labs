module mux4to1(w,s,f);	
   input [0:3]w;
   input [1:0]s;
   output reg f;
   always @(w or s)
   begin
      if(s==2'b00)
         f = w[0];
      else if(s==2'b01)
              f = w[1];
           else if(s==2'b10)
                   f = w[2];
           	else if(s==2'b11)
                   	f = w[3];
   end
endmodule

module lab5p1(W,f);
   input [0:3]W;
   output f;
   wire [0:3]M;
   assign M[0] = ~W[2]|~W[3];
   assign M[1] = ~W[3];
   assign M[2] = ~W[2]&W[3];
   assign M[3] = ~W[3];
   mux4to1 st0(M, W[0:1], f);
endmodule
