#include <stdio.h>
void main()
{
    int n, k, prod = 0, i, j;
    printf("Enter values of n and k:\n");
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            prod = i*j;
            printf("%d\t", prod);
        }
        printf("\n");
    }
}
