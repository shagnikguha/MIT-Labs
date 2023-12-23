#include <stdio.h>
#include <math.h>
void main()
{
    float x, s=1, t=0,p=1,fact=1, i, j;
    int n;
    printf("Enter values of x and n:\n");
    scanf("%f %d", &x, &n);
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=p; j++)
        {
            fact*=j;
        }
        t+=(s*pow(x,p))/fact;
        s *= -1;
        p += 2;
        fact = 1;
    }
    printf("Result is %.2f", t);
}
