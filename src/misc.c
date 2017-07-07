#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "func.h"

either_t *ew_calloc(size_t nmemb, size_t size){
    void *res = calloc(nmemb, size);
    if(res != NULL || (nmemb == 0 || size == 0)){
        return RIGHT(res);
    }
    else {
        return LEFT(error_init(errno));
    }
}

either_t *ew_malloc(size_t size){
    void *res = malloc(size);
    if(res != NULL || size == 0){
        return RIGHT(res);
    }
    else {
        return LEFT(error_init(errno));
    }
}

either_t *ew_realloc(void *ptr, size_t size){
    void *res = realloc(ptr, size);
    if(res != NULL || size == 0){
        return RIGHT(res);
    }
    else {
        return LEFT(error_init(errno));
    }
}
