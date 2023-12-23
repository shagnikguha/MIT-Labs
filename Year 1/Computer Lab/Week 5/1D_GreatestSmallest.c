#include <stdio.h>
void main()
{
    int n, i;
    printf("Enter limit of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter values:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max = arr[0], min = arr[0];
    for(i=1; i<n; i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
        if(min>arr[i])
        {
            min = arr[i];
        }
    }
    printf("Max %d Min %d", max, min);

}
