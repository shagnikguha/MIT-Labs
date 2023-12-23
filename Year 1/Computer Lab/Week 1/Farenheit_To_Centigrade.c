#include <stdio.h>
void main()
{
    double F,C;
    printf("Enter value");
    scanf("%lf", &F);
    C = ((F-32)*5)/9;
    printf("Centrigrade value of F = %lf", C);
}
