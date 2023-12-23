#include <stdio.h>
#include <string.h>
void main()
{
    char string[30][30], temp[30];
    int n, i ,j;
    printf("Enter number of strings:\n");
    scanf("%d",&n);
    printf("Enter Strings:");
    for(i=0;i<n;i++)
    {
        gets(string[i]);
    }
    for(i=0;i<n-1;i++)
    {

        for(j=i+1;j<n;j++)
        {
            if(strcmp(string[i],string[j])>0)
            {
                strcpy(temp, string[i]);
                strcpy(string[i],string[j]);
                strcpy(string[j],temp);
            }
        }
    }
    printf("Sorted list is:\n");
    for(i=0;i<n;i++)
    {
        puts(string[i]);
    }
}
