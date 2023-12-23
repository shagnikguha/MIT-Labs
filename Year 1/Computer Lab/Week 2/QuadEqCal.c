#include <stdio.h>
#include <math.h>
void main()
{
    int k;
    float a,b,c,root1,root2,re,im,disc;
    printf("Enter values of a, b and c:\n");
    scanf("%f %f %f", &a, &b, &c);
    disc = b*b - 4*a*c;
    if(disc<0)
    {
        k=1;
    } else{
        if(disc==0)
        {
            k=0;
        } else{
            k=2;
        }
    }
    switch(k)
    {
    case 0:
        printf("Real and equal roots\n");
        re = b/(2*a);
        printf("Root 1 and Root 2 are %.2f", re);
        break;
    case 1:
        printf("Imaginary roots\n");
        re = -b/(2*a);
        im = pow(fabs(disc),0.5)/(2*a);
        printf("Root 1 = %.2f + %.2fi and Root 2 = %.2f - %.2fi", re, im, re, im);
        break;
    case 2:
        printf("Real and Distinct roots\n");
        root1 = (-b + sqrt(disc))/(2*a);
        root2 = (-b - sqrt(disc))/(2*a);
        printf("Root 1 = %.2f and Root 2 = %.2f", root1, root2);
        break;
    }
}
