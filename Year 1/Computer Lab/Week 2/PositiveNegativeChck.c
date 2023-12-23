#include <stdio.h>
void main()
{
    int d;
    printf("Enter number:\n");
    scanf("%d", &d);
    if(d==0)
    {
        printf("Number is zero");
    } else{
        if(d>0)
        {
            printf("Number is positive");
        } else{
            printf("Number is negative");
        }
    }
}
