#include <stdio.h>
void main()
{
    int num, sum = 0, i;
    printf("Enter number:\n");
    scanf("%d", &num);
    for(i = 1; i<num; i++)
    {
        if(num%i==0)
        {
            sum += i;
        }
    }
    //printf("%d", sum);
    if(num == sum)
    {
        printf("Number is Perfect");
    } else{
        printf("Number is not Perfect");
    }
}
