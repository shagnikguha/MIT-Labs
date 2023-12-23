#include <stdio.h>
void main()
{
    int n, p = 1, i, j;
    printf("Enter value of n:\n");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d\t",p);
            p++;
        }
        printf("\n");
    }
}
