#include <stdio.h>

int main() {
    int a[][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};

    // Declare a pointer to int
    int *p = a;  // No need for &a, 'a' itself is the address of the first element

    // Access the first element of the array using the pointer
    printf("%d", *(*(a+0)+1));


    return 0;
}
