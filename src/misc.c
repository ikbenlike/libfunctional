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

either_t *ew_getenv(const char *name){
    char *res = getenv(name);
    if(res != NULL){
        return RIGHT(res);
    }
    else {
        return LEFT(res);
    }
}

either_t *ew_memchr(const void *s, int c, size_t n){
    void *res = memchr(s, c, n);
    if(res != NULL){
        return RIGHT(res);
    }
    else {
        return LEFT(res);
    }
}

either_t *ew_strchr(const char *s, int c){
    char *res = strchr(s, c);
    if(res != NULL){
        return RIGHT(res);
    }
    else {
        return LEFT(res);
    }
}

either_t *ew_strrchr(const char *s, int c){
    char *res = strrchr(s, c);
    if(res != NULL){
        return RIGHT(res);
    }
    else {
        return LEFT(res);
    }
}

either_t *ew_puts(const char *s){
    int *res = calloc(1, sizeof(int));
    *res = puts(s);
    if(*res != EOF){
        return RIGHT(res);
    }
    else {
        return LEFT(res);
    }
}


