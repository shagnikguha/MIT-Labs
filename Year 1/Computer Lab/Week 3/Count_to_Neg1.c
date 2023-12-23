#include <stdio.h>
void main()
{
    int j,n1 = 0, prime, ccount = 0, pcount = 0;
    do
    {
        printf("Enter number");
        scanf("%d",&n1);
        prime = 1;
        for( j=2; j<n1; j++)
        {
            if(n1%j== 0)
            {
                prime = 0;
                ccount++;
                break;
            }
        }
        if(prime==1)
        {
            pcount++;
        }
    } while(n1!=-1);
    printf("%d Prime Numbers\n", pcount-1);
    printf("%d Composite Numbers\n", ccount);
}
