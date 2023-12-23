#include <stdio.h>
void main()
{
    int s, value, pos, i ,arr[50];
    printf("Enter size of array:\n");
    scanf("%d", &s);
    printf("Enter elements of array:\n");
    for(i=0; i<s; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter value of the element to delete:\n");
    scanf("%d", &value);
    for(i=0; i<s; i++)
    {
        if(arr[i]==value)
        {
            pos = i;
        }
    }
    for(i=pos; i<s; i++)
    {
        arr[i] = arr[i+1];
    }
    for(i=0; i<s-1; i++)
    {
        printf("%d\t", arr[i]);
    }
}
