#include <stdio.h>
int IsPalin(int x)
{
    int temp = x;
    int P = 0;
    while(x>0)
    {
        P=(P*10)+(x%10);
        x /= 10;
    }
    if(P==temp)
    {
        return 1;
    } else{
        return 0;
    }
}
void main()
{
    int num;
    printf("Enter number:\n");
    scanf("%d", &num);
    if(IsPalin(num)==1)
    {
        printf("Is Palindrome");
    } else{
        printf("Is not Palindrome");
    }
}
