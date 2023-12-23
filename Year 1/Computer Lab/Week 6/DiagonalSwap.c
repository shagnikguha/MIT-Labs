#include <stdio.h>
void main()
{
    int n, i, j;
    printf("Enter size of array:\n");
    scanf("%d", &n);
    int A[n][n];
    printf("Enter elements of array:\n");
    for(i=0; i<n; i++)
    {
        for(j=0;j<n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        int t = A[i][i];
        A[i][i] = A[i][n-1-i];
        A[i][n-1-i] = t;
    }
    for(i=0; i<n; i++)
    {
        for(j=0;j<n; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}
