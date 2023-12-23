#include <stdio.h>
void main()
{
    int size, value, pos, i, arr[50];
    printf("Enter size of array:\n");
    scanf("%d", &size);
    printf("Enter elements of the array:\n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter position where you want to insert element:\n");
    scanf("%d", &pos);
    printf("Enter value to be inserted:\n");
    scanf("%d", &value);
    for(i = size-1; i>=pos-1; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = value;
    for(i=0; i<size+1; i++)
    {
        printf("%d\t", arr[i]);
    }
}
