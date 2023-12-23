#include <stdio.h>
void main()
{
    int a, sum, b;
    printf("Enter number:\n");
    scanf("%d",&a);
    b = a;
    sum = 0;
    while(a>0)
    {
        sum += (a%10)*(a%10)*(a%10);
        a /= 10;
    }
    if(sum==b)
    {
        printf("%d is Armstrong", b);
    } else{
        printf("%d is not Armstrong", b);
    }
}
