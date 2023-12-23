`timescale 1ns/1ns
`include "p1.v"
module p1_tb;
reg clk,x,reset;
wire y;
wire[2:0]lo;
p1 uut(clk,x,y,reset,lo);
initial begin
clk=0;
forever #10 clk=~clk;
end 

  initial begin
  $dumpfile("p1_tb.vcd");
  $dumpvars(0,p1_tb);
     x=0;reset=1;#20
     x=1;reset=0;#20
     x=0;#20
     x=1;#20
     x=0;#30
     x=1;#40
     x=0;#40
     x=1;#20
     x=0;#40
       $display("test complete");
       $finish;
       
    end 
    endmodule
