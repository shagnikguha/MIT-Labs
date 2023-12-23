#include <stdio.h>
void main()
{
    int E1, E2, E3, E4;
    int a = 30;
    int b = 10;
    int c = 5;
    int d = 15;
    E1 = (a + b) * c / d;
    E2 = ((a + b) * c) / d;
    E3 = a + (b * c) / d ;
    E4 = (a + b) * (c / d);
    printf("E1 = %d\n E2 = %d\n E3 = %d\n E4 = %d\n", E1, E2, E3, E4);
}
