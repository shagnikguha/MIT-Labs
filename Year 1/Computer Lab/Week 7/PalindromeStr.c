#include <stdio.h>
#include <string.h>
void main()
{
    char s[100];
    int i, l = 0, f = 0;
    printf("Enter string:\n");
    gets(s);
    l = strlen(s);
    for(i = 0;i<(l/2);i++)
    {
        if(s[i]!=s[l-1-i])
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        printf("It is not a palindrome");
    } else{
        printf("It is a palindrome");
    }

}

