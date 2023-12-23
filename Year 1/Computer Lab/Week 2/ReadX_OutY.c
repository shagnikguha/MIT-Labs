#include <stdio.h>
void main()
{
    int x, y;
    printf("Enter value of x:\n");
    scanf("%d",&x);
    if(x==0)
    {
        y=0;
    } else{
        if(y>0)
        {
            y=1;
        } else{
            y=-1;
        }
    }
    printf("%d", y);
}
