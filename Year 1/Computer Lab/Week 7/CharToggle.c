#include <stdio.h>
#include <string.h>
void main()
{
    char s[100];
    int i;
    printf("Enter string:\n");
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>=65&&s[i]<=90)
        {
            s[i] += 32;
        } else{
            if(s[i]>=97&&s[i]<=122)
            {
                s[i] -= 32;
            }
        }
    }
    puts(s);
}
