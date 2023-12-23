#include <stdio.h>
int Fact(int x)
{
    int i = 0;
    int f = 1;
    for(i=1; i<=x; i++)
    {
        f*=i;
    }
    return f;
}
void main()
{

    int n, r, C;
    printf("Enter values of n and r for nCr:'\n");
    scanf("%d %d", &n, &r);
    C = Fact(n)/(Fact(n-r)*Fact(r));
    printf("Value of nCr = %d", C);
}
