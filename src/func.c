#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "func.h"

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

either_t *either_init(int side, void *data){
    either_t *e = calloc(1, sizeof(either_t));
    e->side = side;
    if(side){
        e->right = data;
    }
    else {
        e->left = data;
    }
}

either_t *either(either_t *e, void *(*l)(void*), void *(*r)(void*)){
    if(e == NULL){
        return either_init(S_LEFT, strcpy(calloc(19, sizeof(char)), "arg[0] 'e' == NULL"));
    }
    else if(e->left == NULL && e->right != NULL){
        return either_init(S_RIGHT, r(e->right));
    }
    else if(e->right == NULL && e->left != NULL){
        return either_init(S_RIGHT, l(e->left));
    }
    return either_init(S_LEFT, strcpy(calloc(22, sizeof(char)), "arg[0] 'e' is invalid"));
}

int isright(either_t *e){
    return e->side == S_RIGHT;
}

int isleft(either_t *e){
    return !isright(e);
}

error_t *error_init(int n){
    error_t *er = calloc(1, sizeof(error_t));
    er->err = n;
    er->str = strerror(n);
    return er;
}
