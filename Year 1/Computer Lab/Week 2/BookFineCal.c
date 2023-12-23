#include <stdio.h>
void main()
{
    int d;
    float f;
    printf("Enter number of days the member is late:\n");
    scanf("%d", &d);
    if(d<=5)
    {
        f += 0.50;
    } else{
        if(d>=6 && d<=10)
        {
            f += 1.00;
        } else{
            if(d>10 && d<=30)
            {
                f += 5.00;
            } else{
                f += 10.00;
            }
        }
    }
    printf("Fine is %.2f/=", f);
}
