#include <stdio.h>
#include <string.h>
void main()
{
    int i, j=0, k=0, isFound=0, n=0;
    char str[100], word[20];
    printf("Enter sentence:\n");
    gets(str);
    printf("Enter substring to delete:\n");
    gets(word);
    n = strlen(word);
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]==word[0])
        {
            isFound=1;
            k=i;
            for(j=0; word[j]!='\0'; j++)
            {
                if(str[k]!=word[j])
                {
                    isFound=0;
                    break;
                }
                k++;
            }
            if(j==n)
            {
                break;
            }
        }
    }
    if(isFound==1)
    {
        for(j=i;str[j]!='\0';j++)
        {
            str[j]=str[j+n+1];
        }
        puts(str);
    } else{
        printf("Word not found");
    }
}
