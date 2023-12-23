module btogray(b,g);
parameter n = 4;

input [n-1:0]b;
output [n-1:0]g;
reg [n-1:0]g;

integer i;
always @(b)
begin
g[n-1] = b[n-1];
for(i = n-2;i>=0;i=i-1)
begin
g[i] = b[i+1]^b[i];
end
end
endmodule 
