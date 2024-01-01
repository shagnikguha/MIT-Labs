#include <stdio.h>

struct day {
    int date;
    int time;
} var;

typedef struct{
    int age;
    int grade;
}STUDENT;

int main() {
    struct day struct1;
    struct1.date = 10;
    struct1.time = 11;

    var.date = 11;
    printf("%d\n", var.date);

    printf("%d %d\n", struct1.date, struct1.time);

    struct day struct2 = {32, 48};
    printf("%d %d\n", struct2.date, struct2.time);

    STUDENT s1;
    s1.age = 13;
    s1.grade = 7;
    printf("%d %d\n", s1.age, s1.grade);


    return 0;
}
