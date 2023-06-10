#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (){
    int *ptr1;
    int *ptr2;
    int i;
    srand(time(NULL));

    ptr1 = calloc(10, sizeof(int));
    printf("Valores armazenados em ptr1:\n");
    for(i=0; i<10;i++){
        *(ptr1+i)= rand();
        printf("%d\n", *(ptr1+i));
    }

    ptr2 = calloc(20, sizeof(int));
    printf("\nValores armazenados em ptr2:\n");
    for(i=0; i<20;i++){
        *(ptr2+i)= rand();
        printf("%d\n", *(ptr2+i));
    }
    printf("\nValores copiados:\n");
    for(i=0;i<10;i++){
        memcpy((ptr2+i),(ptr1+i),sizeof(int));
        printf("%d\n", *(ptr2+i));
    }
    return 0;
}