module tFF(t, clk, reset, q);
   input t, clk, reset;
   output reg q;
   always @(negedge clk or negedge reset)
   begin
      if(!reset)
         q <= 0;
      else
      begin
   	if(t)
      	 q <= ~q;
      end
   end
endmodule



