#include <stdio.h>
#include <math.h>
void main()
{
    double pi = 3.14;
    double r, v, a;
    printf("Enter radius");
    scanf("%lf", &r);
    v = (4*pi*pow(r,3))/3;
    a = 4*pi*pow(r,2);
    printf("Volume of sphere %lf\n", v);
    printf("Surface area of sphere %lf\n", a);
}
