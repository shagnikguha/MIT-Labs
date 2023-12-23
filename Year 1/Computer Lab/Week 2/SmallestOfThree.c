#include <stdio.h>
void main()
{
    int a, b, c, min;
    printf("Enter values of a, b, c:\n");
    scanf("%d %d %d", &a, &b, &c);
    min = (a>b)?((b>c)?c:b):((a>c)?c:a);
    printf("%d", min);
}
