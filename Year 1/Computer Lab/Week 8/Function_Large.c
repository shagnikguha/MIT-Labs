#include <stdio.h>
int Largest(int a[], int s)
{
    int i;
    int max = a[0];
    for(i=0; i<s; i++)
    {
        if(max<a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void main()
{
    int n, i;
    printf("Enter size of array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Largest number in array is: %d", Largest(arr, n));
}
