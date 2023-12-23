#include <stdio.h>
void main()
{
    int n = 0, nr = 0;
    printf("Enter number:\n");
    scanf("%d",&n);
    int n1 = n;
    while(n>0)
    {
        nr = (nr*10)+(n%10);
        n = n/10;
    }
    if(n1==nr)
    {
        printf("Is Palindrome");
    } else{
        printf("Is not Palindrome");
    }
}
