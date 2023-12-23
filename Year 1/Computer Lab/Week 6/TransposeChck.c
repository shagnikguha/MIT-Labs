#include <stdio.h>
void main()
{
    int N, i ,j;
    printf("Enter size of array:\n");
    scanf("%d", &N);
    int A[N][N], B[N][N];
    printf("Input elements of array A:\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            B[i][j] = A[j][i];
        }
    }
    int flag = 0;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(A[i][j]!=B[i][j])
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag==1)
    {
        printf("Not Symmetric");
    } else{
        printf("Is Symmetric");
    }

}
