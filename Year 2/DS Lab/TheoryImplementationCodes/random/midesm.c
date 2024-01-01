#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long phone;
    char *name;
} Contact;

void input(Contact *arr, int n){
    for(int i=0; i<n; i++)
    {
        arr[i].name = (char *)malloc(10*sizeof(char));
        printf("Enter number:\n");
        scanf("%ld", &arr[i].phone);
        printf("Enter name:\n");
        scanf(" %s", arr[i].name);
    }
}

long find(Contact *arr, int n, char str[]){
    long f = -1;
    for(int i=0; i<n; i++)
    {
        if(strcmp(arr[i].name, str)==0){
            f = arr[i].phone;
            break;
        }
    }
    return f;
}

void resize(Contact *arr, int n){
    arr = (Contact *)realloc(arr, n);
    printf("Enter name of new Contact:\n");
    arr[n-1].name = (char *)malloc(10*sizeof(char));
    scanf(" %s", arr[n-1].name);
    printf("Enter new number:\n");
    scanf("%ld", &arr[n-1].phone);
}

int main(void){
    int n;
    printf("Enter value of n\n");
    scanf("%d", &n);
    Contact *arr = (Contact *)malloc(n * sizeof(Contact));
    input(arr, n);
    printf("Enter name to find:\n");
    char name[10];
    scanf("%s", name);
    long f = find(arr, n, name);
    printf("%ld", f);
    if(f == -1){
        printf("Name not found\n");
        resize(arr, ++n);
    } else{
        printf("%ld", f);
    }
    for(int i=0;i<n; i++){
        free(arr[i].name);
    }
    free(arr);
}