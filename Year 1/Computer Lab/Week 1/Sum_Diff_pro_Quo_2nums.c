#include <stdio.h>
void main()
{
    int n1, n2, sum, diff, pro, quo;
    printf("Enter value of n1");
    scanf("%d", &n1);
    printf("Enter value of n2");
    scanf("%d", &n2);
    sum = n1 + n2;
    if(n1>n2)
    {
        diff = n1-n2;
    } else{
    diff = n2-n1;
    }
    pro = n1*n2;
    quo = n1/n2;
    printf("Sum in %d\n Diff is %d\n Product is %d\n Quotient is %d\n", sum, diff, pro, quo);
}
