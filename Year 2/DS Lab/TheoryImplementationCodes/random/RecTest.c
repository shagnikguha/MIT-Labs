#include <stdio.h>
#include <string.h>

int fact(int x) {
    if (x == 0) {
        return 1;
    }
    return x * fact(x - 1);
}

void Fib(int x, int i1, int i2) {
    if (x == 0) {
        return;
    }
    int temp = i1;
    i1 += i2;
    printf("%d ", i1);
    Fib(x - 1, i1, temp);
}

int mul(int x, int y) {
    if (y == 0) {
        return 0;
    }
    return x + mul(x, y - 1);
}

int str_len(char str[], int i) {
    if (str[i] == '\0') {
        return 0;
    }
    return 1 + str_len(str, i + 1);
}

int BinaryS(int arr[], int n, int x) {
    int top = n - 1;
    int bot = 0;

    while (top >= bot) {
        int mid = bot + (top - bot) / 2;

        if (arr[mid] == x) {
            return mid; // Element found, return its index
        } else if (arr[mid] < x) {
            bot = mid + 1;
        } else {
            top = mid - 1;
        }
    }

    return -1; // Element not found
}

void BinaryRecS(int arr[], int x, int top, int bot) {
    int mid = bot + (top - bot) / 2;
    
    if (arr[mid] == x) {
        printf("Found");
        return;
    }

    if (bot > top) {
        printf("Not found");
        return;
    }

    if (arr[mid] < x) {
        BinaryRecS(arr, x, top, mid + 1);
    } else {
        BinaryRecS(arr, x, mid - 1, bot);
    }
}

int main(void) {
    printf("%d\n", fact(5));
    printf("0 ");
    Fib(6, 0, 1);
    printf("\n%d\n", mul(2, 3));
    char str[20] = "Hello";
    printf("%d\n", str_len(str, 0));
    int result = BinaryS((int[]){1, 2, 3, 4, 5}, 5, 3);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    BinaryRecS((int[]){1, 2, 3, 4, 5}, 3, 4, 0);
    return 0;
}
