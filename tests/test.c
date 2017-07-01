#include <stdio.h>
#include <stdlib.h>
#include "../src/func.h"

void mul2(void *i){
    *(int*)i *= 2;
}

int greather_than4(void *i){
    if(*(int*)i > 4){
        return 1;
    }
    return 0;
}

int main(int argc, char **argv){
    int a[] = {1, 2, 3, 4, 5};
    printf("%f\n", average(a, 5));
    int *x[] = {a, a + 1, a + 2, a + 3, a + 4};
    map((void**)x, 5, mul2);
    for(int i = 0; i < 5; i++){
        printf("%d\n", *x[i]);
    }
    int *y[5];
    int n = filter((void**)x, (void**)y, 5, greather_than4);
    for(int i = 0; i < n; i++){
        printf("%d\n", *y[i]);
    }
}
