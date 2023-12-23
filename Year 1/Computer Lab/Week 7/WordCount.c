#include <stdio.h>
void main()
{
    char sent[100];
    int i = 0, c = 1;
    printf("Enter sentence:\n");
    gets(sent);
    printf("\n");
    while(sent[i]!='\0')
    {
        if(sent[i]==' ' && sent[i+1]!=' ')
        {
            c++;
        }
        i++;
    }
    printf("No. of words = %d", c);
}
