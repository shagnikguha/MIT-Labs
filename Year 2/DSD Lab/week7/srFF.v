module srFF(s, r, clk, reset, q);
   input s,r,clk,reset;
   output reg q;

   always @(negedge clk)
   begin
   	if(reset)
   	   q <= 0;
   	else
   	begin
   	   if(s==0 && r==1)
   	      q = 0;
   	   if(s==1 && r==0)
   	      q = 1;
   	end
    end
endmodule
   	      
