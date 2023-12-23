#include <stdio.h>
void main()
{
    int n, n1, sum = 0, fact, i, d;
    printf("Enter number:");
    scanf("%d",&n);
    n1 = n;
    while(n!=0)
    {
        fact = 1;
        d = n%10;
        for(i=1; i<=d; i++)
        {
            fact *= i;
        }
        sum = sum + fact;
        n/=10;
        i = 1;
    }
    if(sum==n1)
    {
        printf("Number is Strong");
    } else{
        printf("Number is Not Strong");
    }
}
