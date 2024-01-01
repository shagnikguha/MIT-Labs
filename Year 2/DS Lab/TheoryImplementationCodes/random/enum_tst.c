#include <stdio.h>

enum color{
    RED,
    GREEN,
    YELLOW,
    BLUE,
    ORANGE
};

int main(void){
    enum color c = RED;

    if(c == RED){
        printf("ded");
    }
}