#include <stdio.h>
int CornerSum(int arr[][10], int r, int c)
{
    return(arr[0][0]+arr[0][c-1]+arr[r-1][0]+arr[r-1][c-1]);
}
void main()
{
    int r,c,i,j;
    printf("Enter size of row and column for matrix:\n");
    scanf("%d %d", &r, &c);
    int arr[10][10];
    printf("Enter elements of array:\n");
    for(i=0; i<r; i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Sum of corners is %d", CornerSum(arr, r, c));
}


