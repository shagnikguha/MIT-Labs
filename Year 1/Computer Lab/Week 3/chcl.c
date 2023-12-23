#include <stdio.h>
void main()
{
    int i, d = 5, fact = 1;
    for(i=1; i<=d; i++)
    {
        fact *= i;
    }
    printf("%d", fact);
}
