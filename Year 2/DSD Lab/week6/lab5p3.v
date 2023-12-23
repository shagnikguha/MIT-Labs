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

module dec4to16(W, Y, En);
   input [3:0]W;
   input En;
   output [0:15]Y;
   wire [0:3]M;
   dec2to4 st0(W[3:2], M, En);
   dec2to4 st1(W[1:0], Y[0:3], M[0]);
   dec2to4 st2(W[1:0], Y[4:7], M[1]);
   dec2to4 st3(W[1:0], Y[8:11], M[2]);
   dec2to4 st4(W[1:0], Y[12:15], M[3]);
endmodule

module lab5p3(W,f);
   input [3:0]W;
   wire [0:15]M;
   output f;
   dec4to16 st0(W,M,1'b1);
   assign f = M[1]|M[4]|M[6]|M[8]|M[9]|M[13]|M[15];
endmodule
