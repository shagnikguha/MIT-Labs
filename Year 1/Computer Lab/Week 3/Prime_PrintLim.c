#include <stdio.h>
void main()
{
    int l, h, i, prime, c;
    printf("Enter the limits:\n");
    scanf("%d%d",&l,&h);
    while(l<=h)
    {
        i = l;
        prime = 1;
        c = 2;
        while(c<=i/2)
        {
            if(i%c==0)
            {
                prime = 0;
                break;
            }
            c++;
        }
        if(prime==1)
        {
            printf("%d\t",i);
        }
        l++;
    }
}
