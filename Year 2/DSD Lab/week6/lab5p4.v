module dec2to4(w, y, e);
   input [1:0]w;
   input e;
   output reg [0:3]y;
   always @(e, w)
   begin
      y = 4'b0000;
      if(w==2'b00&e==1)
         y[0] = 1;
      else if(w==2'b01&e==1)
      	      y[1] = 1;
      	   else if(w==2'b10&e==1) 
      	   	   y[2] = 1;
      	   	else if(w==2'b11&e==1)
      	   		y[3] = 1;
   end
endmodule

module lab5p4(W, f);
   input [2:0]W;
   output f;
   wire [0:7]M;
   dec2to4 st0(W[1:0], M[0:3], ~W[2]);
   dec2to4 st1(W[1:0], M[4:7], W[2]);
   assign f = M[3]|M[5]|M[6]|M[7]; 
endmodule
