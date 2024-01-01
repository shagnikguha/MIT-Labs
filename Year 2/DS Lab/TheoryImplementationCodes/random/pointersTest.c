#include <stdio.h>
#include <stdlib.h>

int *chck(int *x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
    int *temp_ptr = &temp;
    return temp_ptr; 
}

int binarySearch(int arr[], int size, int target) {
    int *left = arr;
    int *right = arr + size - 1; // Pointer to the last element

    while (left <= right) {
        int *mid = left + (right - left) / 2; // Calculate the middle pointer
        
        if (*mid == target) {
            return mid - arr; // Return the index of the found element
        } else if (*mid < target) {
            left = mid + 1; // Adjust the left pointer
        } else {
            right = mid - 1; // Adjust the right pointer
        }
    }

    return -1; // Element not found
}

int main(void){
    /*
    char p;
    char c;
    printf("%p %p\n", &p, &c);
    int x = 10;
    int y = 9;
    int *ptr1 = &x;
    int *ptr2 = &y;
    printf("%d %d\n", *ptr1, *ptr2);
    //ptr2 = &x;
    //printf("%d %d\n", *ptr1, *ptr2);
    int *val = chck(ptr1, ptr2);
    printf("%d\n", *val); 
    printf("%d %d\n", *ptr1, *ptr2);
    */
   /*
   int arr[] = {1,2,3,4,5};
   int *ptr = &arr[1]; //as arr is already a pointer, no need to put &
   printf("%d\t", *ptr);
   for(int i=0; i<4; i++){
    printf("%d\n", ptr[i]);
   }
   */
  /*
  int x = 42;
    int y = 99;
    int *ptr1 = &x;
    int *ptr2 = &y;
    printf("%p %p\n", ptr1, ptr2);

    if (ptr1 < ptr2) {
        printf("ptr1 is before ptr2 in memory locations.\n");
    }
    */
    int arr[5];
    int *ptr = arr;
    for(int i=0; i<5; i++,ptr++)
    {
        scanf("%d", ptr);
    }
    ptr = arr;
    for(int i=0; i<5; i++,ptr++)
    {
        printf("%d\t", *ptr);
    }




}