#include <stdio.h>

// Define a union named 'MyUnion'
union MyUnion {
    int integer;
    float floating;
    char character;
};

int main() {
    // Declare a variable of the 'MyUnion' type
    union MyUnion data;

    // Assign values to the members of the union
    data.integer = 42;
    printf("Integer value: %d\n", data.integer);

    data.floating = 3.14;
    printf("Float value: %f\n", data.floating);

    data.character = 'A';
    printf("Character value: %c\n", data.character);

    // The union shares memory, so only the last assigned member's value is preserved
    printf("After assigning character: %d\n", data.integer);
    printf("After assigning character: %f\n", data.floating);

    return 0;
}
