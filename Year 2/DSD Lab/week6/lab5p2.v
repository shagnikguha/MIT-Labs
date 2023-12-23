module mux8to1(s,w,f);
   input [2:0]s;
   input [0:7]w;
   output reg f;
   always @(s,w)
   begin
      case(s)
         0: f=w[0];
         1: f=w[1];
         2: f=w[2];
         3: f=w[3];
         4: f=w[4];
         5: f=w[5];
         6: f=w[6];
         7: f=w[7];
         default: f=0;
      endcase
   end
endmodule

module lab5p2(G,B);
   input [3:0]G;
   output [3:0]B;
   wire [0:7]M3, M2, M1, M0;
   assign M3 = 8'b00001111;
   assign M2 = 8'b00111100;
   assign M1 = 8'b01101001;
   assign M0 = {G[0],~G[0],G[0],~G[0],G[0],~G[0], G[0],~G[0]};
   mux8to1 st0(G[3:1], M3, B[3]);
   mux8to1 st1(G[3:1], M2, B[2]);
   mux8to1 st2(G[3:1], M1, B[1]);
   mux8to1 st3(G[3:1], M0, B[0]);
endmodule
