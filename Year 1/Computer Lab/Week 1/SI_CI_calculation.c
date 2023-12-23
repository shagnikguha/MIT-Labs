#include <stdio.h>
#include <math.h>
void main()
{
    double P,N,R;
    double CI, SI;
    printf("Enter P");
    scanf("%lf", &P);
    printf("Enter N");
    scanf("%lf", &N);
    printf("Enter R");
    scanf("%lf", &R);
    SI = (P*N*R)/100;
    CI = (P*pow((1+R/100),N))-P;
    printf("SI is %lf\n", SI);
    printf("CI is %lf\n", CI);
}

