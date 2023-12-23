                  #include <stdio.h>
void main()
{
    int n, i , j, ch;
    printf("Enter limit of array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter values:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter 1 for ascending, 2 for descending:\n");
    scanf("%d", &ch);
    if(ch==1)
    {
        printf("Ascending order:\n");
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-1-i; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int n = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = n;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            printf("%d\t", arr[i]);
        }
    }  else{
        //descending
        printf("Descending order:\n");
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n-1-i; j++)
            {
                if(arr[j]<arr[j+1])
                {
                    int n = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = n;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}
