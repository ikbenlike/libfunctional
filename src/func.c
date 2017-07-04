#include <string.h>

size_t map(void **array, size_t len, void (*func)(void*)){
    size_t i;
    for(i = 0; i < len; i++){
        func(array[i]);
    }
    return i;
}

size_t filter(void **array, void **res, size_t len, int (*func)(void*)){
    size_t i;
    size_t x = 0;
    for(i = 0; i < len; i++){
        if(func(array[i])){
            res[x++] = array[i];
        }
    }
    return x;
}

float average(int *array, size_t len){
    int sum = 0;
    size_t i;
    for(i = 0; i < len; i++){
        sum += array[i];
    }
    return (float)sum/(float)i;
}

size_t reduce(void **array, void *res, size_t len, void (*func)(void*, void*)){
    size_t i;
    for(i = 0; i < len; i++){
        func(res, array[i]);
    }
    return i;
}
