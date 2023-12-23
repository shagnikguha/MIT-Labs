#include <stdio.h>
void main()
{
    int N1, N2, N3;
    printf("Enter values of N1, N2, and N3:\n");
    scanf("%d %d %d", &N1, &N2, &N3);
    if(N1>N2)
    {
        if(N1>N3)
        {
            printf("%d", N1);
        } else{
            printf("%d", N3);
        }
    } else{
        if(N2>N3)
        {
            printf("%d", N2);
        } else{
            printf("%d", N3);
        }
    }
}
