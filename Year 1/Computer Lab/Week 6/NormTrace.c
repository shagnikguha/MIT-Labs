#include <stdio.h>
#include <math.h>
void main()
{
    int n, t = 0, s = 0, norm, i = 0,j=0;
    printf("Enter size of array:\n");
    scanf("%d", &n);
    int A[n][n];
    for(i = 0; i<n;i++)
    {
        for(j = 0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for(i = 0; i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            s+=A[i][j];
            if(i==j)
            {
                t+=A[i][j];
            }
        }
    }
    norm = sqrt(s);
    printf("%d %d", t, norm);
}
